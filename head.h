#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include<time.h>

typedef struct {
SDL_Surface *image ;

char txt[60];
int answer;
} enigme;

typedef struct {
int ji;
SDL_Surface *bck ;
}background;

typedef struct {
int ij;
SDL_Surface *sprite;
}personne;


void genererEnigme(enigme * e, char *nomfichier);
void afficherEnigme(enigme e, SDL_Surface * screen);

void sauvegarder (personne p, background b, char * nomfichier) ;
int charger ( personne * p, background *b , char * nomfichier) ;


#endif // HEAD_H_INCLUDED
