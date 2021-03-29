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
char txt[270];
char *image;
char *key;
char *tt1;
char *tt2;
char *tt3;
int answer;

} enigme;


void genererEnigme(enigme * e, char *nomfichier);
void afficherEnigme(enigme e, SDL_Surface * screen);



#endif // HEAD_H_INCLUDED
