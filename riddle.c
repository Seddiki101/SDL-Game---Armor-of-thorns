#include"head.h"

void genererEnigme(enigme * e, char *nomfichier)
{int r=0,i;

srand(time(NULL));
r=random()%5;

FILE *f=NULL;
f=fopen(nomfichier,"r");


switch(r)
    {
    
    case 0:
        e->answer=3;
        e->image="Puzzle/q1.png";
        e->key="Puzzle/k1.png";
        e->tt1="g: raise the bridge ";
        e->tt2="h: do nothing ";
        e->tt3="j: lower the bridge";
        break;
    case 1:
        e->answer=1;
         e->image="Puzzle/q2.png";
        e->key="Puzzle/k2.png";
        e->tt1="g: 09d";
        e->tt2="h: 10d";
        e->tt3="j: 11d";
        break;
    case 2:
        e->answer=2;
         e->image="Puzzle/q3.png";
        e->key="Puzzle/k3.png";
        e->tt1="g: 4d";
        e->tt2="h: 5d";
        e->tt3="j: 6d";
        break;
    case 3:
        e->answer=3;
         e->image="Puzzle/q4.png";
        e->key="Puzzle/k4.png";
        e->tt1="g: 23s";
        e->tt2="h: 19s";
        e->tt3="j: 21s";
        break;
        
    case 4:
        e->answer=1;
        e->image="Puzzle/q5.png";
        e->key="Puzzle/k5.png";
        e->tt1="g: no";
        e->tt2="h: maybe";
        e->tt3="j: yes";
        break;
            
       } 
       
 //now reading the question   
for(i=0;i<=r;i++)
{ fgets(e->txt, sizeof(e->txt), f); }



}








////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void afficherEnigme(enigme e, SDL_Surface * screen)
{
SDL_Surface *back=NULL,*key=NULL,*txt=NULL,*Yes=NULL,*No=NULL,*Timer=NULL,*t1=NULL,*t2=NULL,*t3=NULL;
SDL_Rect postxt, posbck,posY,posN,post1,post2,post3,pok;
int cnt=1,temps=0,reponse=-1,past=0,now=0;
SDL_Event event;




//positions
 postxt.x=250 ;
 postxt.y=150;
 
 posbck.x=0 ;
 posbck.y=0;

 posY.x=600;
 posY.y=500;
 
 posN.x= 200;
 posN.y=500;

post1.x=1000;
post1.y=370;

post2.x=1050;
post2.y=500;

post3.x=1020;
post3.y=645;

pok.x=600;
pok.y=450;

//if it took too long to show just add animation at the start

//image load
back=IMG_Load(e.image);
key=IMG_Load(e.key);
Yes=IMG_Load("Puzzle/0.png");
No=IMG_Load("Puzzle/1.png");
Timer=IMG_Load("Puzzle/timer.png");

//txt
TTF_Font *police;
TTF_Init();
SDL_Color couleur  = {0, 0, 0};
police =TTF_OpenFont("Roman.ttf",20);

txt= TTF_RenderText_Blended(police,e.txt, couleur);
t1= TTF_RenderText_Blended(police,e.tt1, couleur);
t2= TTF_RenderText_Blended(police,e.tt2, couleur);
t3= TTF_RenderText_Blended(police,e.tt3, couleur);

TTF_CloseFont(police);

//sound
 SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetCaption("SDL_Mixer",NULL);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
    Mix_Chunk *son=NULL,*son0=NULL,*son1=NULL;
    son=Mix_LoadWAV("Puzzle/mys.wav");
    son0=Mix_LoadWAV("Puzzle/right.wav");
    son1=Mix_LoadWAV("Puzzle/wrong.wav");

//playing sound at the start of enigme
Mix_PlayChannel(1,son,0);
//cleaning the screen to brighten our damned future

SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));

while(cnt)
  { 
  SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
     SDL_BlitSurface(back,NULL,screen,&posbck);
     SDL_BlitSurface(key,NULL,screen,&pok); 
       SDL_BlitSurface(txt,NULL,screen,&postxt);       

SDL_BlitSurface(t1,NULL,screen,&post1);
SDL_BlitSurface(t2,NULL,screen,&post2);
SDL_BlitSurface(t3,NULL,screen,&post3);
   
   SDL_Flip(screen);
   
 
       temps=SDL_GetTicks();
       
       if(temps>30000)
       {
          //the score doesn t change or decrements 
          //show image : you ran out of time
         
         SDL_BlitSurface(Timer,NULL,screen,&posbck); 
          SDL_Flip(screen);
          SDL_Delay(3000);
          cnt=0;
        }
       
       
 //animating 
   now=temps;
   
   if((now-past)>1000){
   pok.x-=2;
   past=now;      
                      }    
   SDL_Flip(screen);    
       
       SDL_PollEvent(&event);
switch(event.type)
             {
             
             case SDL_KEYDOWN:
 
 if(event.key.keysym.sym==SDLK_g)
  {reponse = 1;
          if(reponse==e.answer) {SDL_BlitSurface(Yes,NULL,screen,&posY);Mix_PlayChannel(-1,son0,0);} 
               else{SDL_BlitSurface(No,NULL,screen,&posN);Mix_PlayChannel(-1,son1,0);} 
          SDL_Flip(screen);
          break;
          }
            
          
   else if(event.key.keysym.sym==SDLK_h)
  {reponse =2 ;
    if(reponse==e.answer) {SDL_BlitSurface(Yes,NULL,screen,&posY);Mix_PlayChannel(-1,son0,0);} 
                 else{SDL_BlitSurface(No,NULL,screen,&posN);Mix_PlayChannel(-1,son1,0);}
          SDL_Flip(screen);
          break;
          }
          
          
 
  else if(event.key.keysym.sym==SDLK_j)
  { reponse=3;
      if(reponse==e.answer) {SDL_BlitSurface(Yes,NULL,screen,&posY);Mix_PlayChannel(-1,son0,0);} 
                 else{SDL_BlitSurface(No,NULL,screen,&posN);Mix_PlayChannel(-1,son1,0);}
          SDL_Flip(screen);}      
             
             
             }//switchi
  

} //while

//free(e);
//only shows and receives input
 SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));    
}

