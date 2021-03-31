#include "header.h"




void initPerso(perso *p)
{
  (*p).sheet=IMG_Load("sprtest.png");
 (*p).photo_vie=IMG_Load("heart.png");

  (*p).posSprite.x=0;
  (*p).posSprite.y=0;
  (*p).posSprite.w=400/4;
  (*p).posSprite.h=400/4;




  (*p).position.x=0; //POSITION INITIALE
  (*p).position.y=550;

(*p).position_vie.x=10;
(*p).position_vie.y=10;

(*p).direction=-1;
(*p).vie=3;
(*p).score=0;


(*p).police=TTF_OpenFont("Roman.ttf",100);
	(*p).Noir.r=255;
	(*p).Noir.g=255;
	(*p).Noir.b=255;

(*p).position_score.x=620;
(*p).position_score.y=0;



}//fin initialisation


void afficherPerso(perso p, SDL_Surface * screen)
{

  int i;
  SDL_BlitSurface(p.sheet,&p.posSprite,screen,&p.position);



if (p.vie==1)
SDL_BlitSurface(p.photo_vie,NULL,screen,&p.position_vie);
else if (p.vie==2)
{
SDL_BlitSurface(p.photo_vie,NULL,screen,&p.position_vie);

(p).position_vie.x=10;
(p).position_vie.y=10;
	 SDL_BlitSurface(p.photo_vie,NULL,screen,&p.position_vie);

}
else if (p.vie==3)
{
SDL_BlitSurface(p.photo_vie,NULL,screen,&p.position_vie);

(p).position_vie.x=140;
(p).position_vie.y=10;
	 SDL_BlitSurface(p.photo_vie,NULL,screen,&p.position_vie);

(p).position_vie.x=270;
(p).position_vie.y=10;
	 SDL_BlitSurface(p.photo_vie,NULL,screen,&p.position_vie);
}


// SCORE 


char str[10];


  sprintf(str, "%d", p.score);

	p.photo_score= TTF_RenderText_Blended(p.police,str,p.Noir);

			SDL_BlitSurface(p.photo_score,NULL,screen,&p.position_score); //DISPLAY TEXT 


  
}//fin fonction affichage

void animerPerso( perso * p)
{
  if ((*p).direction==0)
    (*p).posSprite.y=0;
  else if ((*p).direction==1)
    (*p).posSprite.y=100;

    if ((*p).posSprite.x==400-(*p).posSprite.w) //change with sprite WIDTH
      (*p).posSprite.x=0;
    else
      (*p).posSprite.x = (*p).posSprite.x + (*p).posSprite.w;

}//fin fonction animer



void deplacer( perso *p)
{

  if ((*p).direction==0)
    (*p).position.x++;
  else if ((*p).direction==1)
    (*p).position.x--;
}//fin fonction deplacer


SDL_Surface * SDL_initialize(  int largeur, int hauteur)
{

SDL_Init(SDL_INIT_VIDEO |SDL_INIT_AUDIO);	// video/audio initialisation

    if (SDL_Init(SDL_INIT_VIDEO)!=0)		//check for video error
    {
        printf("\n erreur init du video: %s",SDL_GetError());
        SDL_Quit();
        EXIT_FAILURE;
    }
    else if (SDL_Init(SDL_INIT_AUDIO)!=0)	//check for sound error 1
    {
	printf("SDL sound erreur: %s\n", SDL_GetError());
        SDL_Quit();
        EXIT_FAILURE;
    }


Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );	//more sound initialisation


     if(Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 )!=0) 	// //check for sound error 2
 	{
        printf("SDL Sound erreur: %s\n", Mix_GetError());
        Mix_CloseAudio();
        SDL_Quit();
        EXIT_FAILURE;
    	}

TTF_Init();	//text initialisation
	if (TTF_Init()!=0)	//checking for text error
	{
        printf("SDL Sound erreur: %s\n", Mix_GetError());
        Mix_CloseAudio();
        SDL_Quit();
        EXIT_FAILURE;
    	}

    SDL_Surface *screen=NULL; 	// window initialisation
    screen= SDL_SetVideoMode(largeur,hauteur,0,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
    if (screen==NULL)	//checking for window errors
    {
        printf("\n erreur init du screen: %s",SDL_GetError());
        EXIT_FAILURE;
    }



}
