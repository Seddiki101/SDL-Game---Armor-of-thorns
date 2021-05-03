#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define mapw 12800
#define maph 720


typedef struct
{
SDL_Surface *imageES[2];//image de l'entite secondaire
SDL_Rect posES;//pos de l'entite secondaire
SDL_Rect spriteES;//position pour la spritesheet de l'entite secondaire
int xmin;//la position minimale
int xmax;//la position maximale
int d;//la direction
int dea;// direction aleatoire
int num;//numero si l'on affiche ou non
int speed;//la vitesse
int follow;//state(si il te suit ou non)
} EntiteS;//la structure de l'entite secondaire

typedef struct
{
  SDL_Surface *img ;
  SDL_Rect pos ;

}Object;

void initback(Object *backg  );
void setup (SDL_Surface *ecran, Object *backg );
void initialisation_e_s(EntiteS t[]);
void affichage_entites_secondaires(EntiteS t[],SDL_Surface *ecran, Object backg);
void animation_e_s(EntiteS t[]);
void gestion_pos_e_s(EntiteS t[]);
void deplacement_alea(EntiteS dep);

#endif // FUNCTION_H_INCLUDED
