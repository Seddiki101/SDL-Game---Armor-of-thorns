#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#define w 1280
#define h 720

#define mapw 12800
#define maph 720

typedef struct 
{
  SDL_Surface *img ;
  SDL_Rect pos ; 

}Objet;



void init(Objet *backg  )  ;
void setup (SDL_Surface *screen, Objet *backg ) ;
void scrolling_Right (SDL_Surface *screen , Objet *backg) ;
void scrolling_Left (SDL_Surface*screen , Objet *backg) ;
void event(SDL_Surface *screen ,Objet *boat ,int *running) ;
void free_back(Objet *backg, Mix_Music *musique) ;
