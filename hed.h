#ifndef HED_H_INCLUDED
#define HED_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


typedef struct {
//int etat;
SDL_Surface *image ;
SDL_Rect position ;

} button;

typedef struct {
 int etat;
SDL_Surface *image;
SDL_Rect position ;
}background;


void Picload (button b[],background bc[]);
void Pos (button b[],background bc[]);
void afficbck (background B,SDL_Surface* bck);
void affichbtn (button B,SDL_Surface *screen,Mix_Chunk *son);


#endif // HED_H_INCLUDED
