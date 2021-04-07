#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

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
}ES;//la structure de l'entite secondaire



void initialisation_e_s(ES t[8]);
void affichage_entites_secondaires(ES t[8],SDL_Surface *ecran);
void animation_e_s(ES t[8]);
void dep_alea(ES dep)

