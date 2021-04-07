#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "backgscroll.h"
#include <SDL/SDL_mixer.h>
void init(Objet *backg  ) 
{
  SDL_WM_SetCaption("scrolling", NULL);

  backg->img=IMG_Load("backg.png") ;
  backg->pos.x=0 ;
  backg->pos.y=0 ;
  
  

}

void setup (SDL_Surface *screen, Objet *backg )
{
  SDL_BlitSurface(backg->img,NULL,screen, &(backg->pos));

  SDL_Flip(screen) ;
}



void scrolling_Right(SDL_Surface *screen , Objet *backg)
{
 if (backg->pos.x<=6118)
   backg->pos.x+=5 ;

   SDL_BlitSurface(backg->img,&(backg->pos),screen, NULL);
}

void scrolling_Left(SDL_Surface*screen , Objet *backg)
{
 if (backg->pos.x>=0)
   backg->pos.x-=5 ;
 SDL_BlitSurface(backg->img,&(backg->pos),screen, NULL);  
}

void event(SDL_Surface *screen ,Objet *backg,int *running )
{
 SDL_Event event;



 SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                *running = 0;
            break;
            case SDL_KEYDOWN:

               switch(event.key.keysym.sym)

                  {
                   case SDLK_ESCAPE: // Flèche droite
            	
                *running = 0;
                          

                     break;

                     case SDLK_RIGHT: // Flèche droite
            	
                          scrolling_Right(screen ,backg) ;

                          SDL_Flip(screen);
                          

                     break;

                     case SDLK_LEFT: // Flèche gauche
                          scrolling_Left (screen ,backg) ;

                          SDL_Flip(screen);
                          

                     break;
              

                  }

            break;    
        }

}


void free_back(Objet *backg,Mix_Music *musique)
{


 SDL_FreeSurface (backg->img) ;
 Mix_FreeMusic(musique); //Libération de la musique
   Mix_CloseAudio(); //Fermeture de l'API

 SDL_Quit () ;

}//fin fonction free
