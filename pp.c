#include"hed.h"

int main(int argc, char *argv[])
{
SDL_Surface *screen=NULL,*txt=NULL,*voiture=NULL;
SDL_Rect positiontxt,positionvoiture;
button b[20];
background bc[3];
background b_actuel;
SDL_Event event,evt;
positionvoiture.x=0;
positionvoiture.y=625;

voiture=IMG_Load("v.png");
int continuer=1,x=0,loop=1,move=1,done=1;

////////////   functions       ///////////////         //////////// 
   Picload(b,bc);
   Pos (b,bc);

//////////// text     //////////////          ////////////
   positiontxt.x=1000;
        positiontxt.y=690;
  TTF_Font *police;
TTF_Init();
SDL_Color couleur  = {255, 255, 255};
police =TTF_OpenFont("Roman.ttf",20);
txt= TTF_RenderText_Blended(police, "Armor_of_Thorns", couleur);
TTF_CloseFont(police);

//////////// Window mode     //////////////          ////////////

    screen = SDL_SetVideoMode(1280,720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Game", NULL);   

/////////////partie son     //////////////           //////////////

       Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
    Mix_VolumeMusic(MIX_MAX_VOLUME/3);
    Mix_Music *music =NULL;
    Mix_Chunk *son=NULL;
    music=Mix_LoadMUS("menu01.mp3"); /* charger music */
    son=Mix_LoadWAV("son1.wav");
    Mix_PlayMusic(music,-1);/*jouer la music -1 fois => eternal pain  */
    
    
    Mix_VolumeMusic(MIX_MAX_VOLUME/3);
 
//cleaning the screen to brighten our damned future
SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));

//starting with static elements
b_actuel=bc[0];
 SDL_BlitSurface(b_actuel.image,NULL,screen,&b_actuel.position); //background
 SDL_BlitSurface(txt,NULL,screen,&positiontxt); //background
affichbtn (b[0],screen,son); 
affichbtn (b[1],screen,son);    
affichbtn (b[2],screen,son); 

 SDL_Flip(screen);

while(continuer)
{

SDL_PollEvent(&event);
switch(event.type)
{
case SDL_QUIT:
continuer=0;
break;

case SDL_KEYDOWN:
 
 if(event.key.keysym.sym==SDLK_o)
  {
   if(b_actuel.etat==1)
   {
   break;
   }
   else
   {
   
   b_actuel=bc[1];
 SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
   SDL_BlitSurface(b_actuel.image,NULL,screen,&b_actuel.position); 
   
   SDL_BlitSurface(b[7].image,NULL,screen,&b[7].position);	//sound bar
	SDL_BlitSurface(b[8].image,NULL,screen,&b[8].position); //changer
	SDL_BlitSurface(b[6].image,NULL,screen,&b[6].position);	
	SDL_Flip(screen);
	
   }
   }
   else if(event.key.keysym.sym==SDLK_q)        
   {
   continuer=0;
   SDL_Delay(300);
   }
   
 else if(event.key.keysym.sym==SDLK_ESCAPE)
 {
 if(b_actuel.etat==0)
 {
 break;
 }
 else
 {
 b_actuel=bc[0];
 SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
   SDL_BlitSurface(b_actuel.image,NULL,screen,&b_actuel.position);
  affichbtn (b[0],screen,son); 
affichbtn (b[1],screen,son);    
affichbtn (b[2],screen,son); 
SDL_Flip(screen); 
 }
 
 }
  
 ///
 
 else if(event.key.keysym.sym==SDLK_DOWN)
 {           
 
 //continuer=0;
                if(x==0)
               { 
               SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
b_actuel=bc[0];
 SDL_BlitSurface(b_actuel.image,NULL,screen,&b_actuel.position); //background
affichbtn (b[3],screen,son); 
affichbtn (b[1],screen,son);    
affichbtn (b[2],screen,son); 
SDL_Flip(screen);
SDL_Delay(300);
x=1;
               break;}
               
               else if(x==1)
              {  
 SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
b_actuel=bc[0];
 SDL_BlitSurface(b_actuel.image,NULL,screen,&b_actuel.position); //background
affichbtn (b[0],screen,son); 
affichbtn (b[4],screen,son);    
affichbtn (b[2],screen,son); 
SDL_Flip(screen);  
SDL_Delay(300);
              x=2;
               break;}
               
            else if(x==2)
              {  
               SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
b_actuel=bc[0];
 SDL_BlitSurface(b_actuel.image,NULL,screen,&b_actuel.position); //background
affichbtn (b[0],screen,son); 
affichbtn (b[1],screen,son);    
affichbtn (b[5],screen,son); 
SDL_Flip(screen);   
SDL_Delay(300);     
              
              x=0;
               break;}
               
    
               
 }
                
   else if(event.key.keysym.sym==SDLK_UP)        
   {
                 if(x==0)
               {
               SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
b_actuel=bc[0];
 SDL_BlitSurface(b_actuel.image,NULL,screen,&b_actuel.position); //background
affichbtn (b[3],screen,son); 
affichbtn (b[1],screen,son);    
affichbtn (b[2],screen,son); 
SDL_Flip(screen);
SDL_Delay(300); 
               x=2;
               break;}
               
               else if(x==2)
              {  
              
               SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
b_actuel=bc[0];
 SDL_BlitSurface(b_actuel.image,NULL,screen,&b_actuel.position); //background
affichbtn (b[0],screen,son); 
affichbtn (b[1],screen,son);    
affichbtn (b[5],screen,son); 
SDL_Flip(screen);   
SDL_Delay(300);     
              x=1;
               break;}
               
            else if(x==1)
              {  
              SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
b_actuel=bc[0];
 SDL_BlitSurface(b_actuel.image,NULL,screen,&b_actuel.position); //background
affichbtn (b[0],screen,son); 
affichbtn (b[4],screen,son);    
affichbtn (b[2],screen,son); 
SDL_Flip(screen);  
SDL_Delay(300);
              x=0;
               break;}
      }
break;      
                 //start erasing     
               
                 
           case SDLK_SPACE: done =1; 
            
            if(x==0){ continuer=0 ; break;}
            
         else if(x==2&&done==1) {
         bc[0].etat=0;
         SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
       
                                }

            else if(x==1&&done==1)
            {SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
             afficbck(bc[0],screen);
             
            break;} 
            
              break ;
               //testing end 
 
 
 
 ///
  case SDL_MOUSEBUTTONDOWN:
  
   if (event.button.button==SDL_BUTTON_LEFT) //for sound
	{
	if(b_actuel.etat==1)
	{
        if((event.button.x>=b[7].position.x)&&(event.button.y>=b[7].position.y)&&(event.button.x<=(b[7].position.x+245))&&(event.button.y<=(b[7].position.y+49)))
		{
		move=1;
		b[8].position.x=event.button.x;
		b_actuel=bc[1];
 SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
   SDL_BlitSurface(b_actuel.image,NULL,screen,&b_actuel.position); 
   
   SDL_BlitSurface(b[7].image,NULL,screen,&b[7].position);	//sound bar
	SDL_BlitSurface(b[8].image,NULL,screen,&b[8].position); //changer
	SDL_BlitSurface(b[6].image,NULL,screen,&b[6].position);	
	SDL_Flip(screen);
		Mix_VolumeMusic(((b[8].position.x-350)*100)/245);
		
		}
	else if ((event.button.x>=b[6].position.x)&&(event.button.y>=b[6].position.y)&&(event.button.x<=(b[6].position.y+230))&&(event.button.y<=(b[6].position.y+98)))
		{
		SDL_WM_ToggleFullScreen(screen);
	
		}

}
}

case SDL_MOUSEMOTION:


if((event.motion.x<300&&event.motion.x>50)&&(event.motion.y<465&&event.motion.y>400))
{
SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));

afficbck(bc[0],screen);
affichbtn (b[3],screen,son);
affichbtn (b[1],screen,son); 
affichbtn (b[2],screen,son);
SDL_BlitSurface(voiture,NULL,screen,&positionvoiture); 
if(positionvoiture.x<1200)
{
positionvoiture.x+=20; 
}
else
{positionvoiture.x=0;
}
SDL_Flip(screen);
}

if((event.motion.x<300&&event.motion.x>50)&&(event.motion.y<565&&event.motion.y>500))
{
SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
afficbck(bc[0],screen);
affichbtn (b[0],screen,son); 
affichbtn (b[4],screen,son);    
affichbtn (b[2],screen,son);
SDL_BlitSurface(voiture,NULL,screen,&positionvoiture); 
if(positionvoiture.x<1200)
{
positionvoiture.x+=20; 
}
else
{positionvoiture.x=0;
}
SDL_Flip(screen);
}
if((event.motion.x<300&&event.motion.x>50)&&(event.motion.y<665&&event.motion.y>600))
{
SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
afficbck(bc[0],screen);
affichbtn (b[0],screen,son); 
affichbtn (b[1],screen,son);
affichbtn (b[5],screen,son);
SDL_BlitSurface(voiture,NULL,screen,&positionvoiture);
if(positionvoiture.x<1200)
{
positionvoiture.x+=20; 
}
else
{positionvoiture.x=0;
}
SDL_Flip(screen);}
 
 break;   


  	

 

  


}
} //while
}
