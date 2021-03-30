/**
* @struct map
* @brief struct for map
*/

#ifndef map_H_INCLUDED
#define map_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "perso.h"
#include "entite.h"


typedef struct {
SDL_Surface *minimap ;
SDL_Rect minimap_pos;

SDL_Surface *mini_perso;
SDL_Rect pos_perso_map;

SDL_Surface *mini_entite;
SDL_Rect pos_entite_map;
}map ;


typedef struct 
{
    int tempsdebut;
    int mm; 
    int ss;
    Text temps;
    
} Time;

typedef struct {
    SDL_Surface* textSur;
    SDL_Rect posText;
    SDL_Color coulTxt;
    TTF_Font* poli;
char txt[20];
}Text;







void initmap (minimap *m,SDL_Surface *screen) ;

void entite_map(map *m, entite *e);
void afficherminimap(map *m , SDL_Surface *screen,entite *e);
void mise_a_jour_map(map *m , SDL_Surface *screen, perso *p, entite *e);
void affichertemps(Time T,SDL_Surface *screen);
int collisionPP(perso *p, entite *e)


#endif
