#ifndef ENIGMA_HEADER_H_INCLUDED
#define ENIGMA_HEADER_H_INCLUDED

// Previously modified by :
//
// Last modified by : ilyes
//
// 165503 is funny. Funny numbers go brrrrrrrrrrrrrrrrr

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct
{
    char question[512];
    char question2[512];
    char answer1[32];
    char answer2[32];
    char answer3[32];
    int check;
} enigma;


int Random (int lower, int upper);
float RandomFloat(float lower, float upper);
float SquareRoot (float number);
float Power (float x, int y);
char *strrev (char *str);

void DrawOverlay (SDL_Surface *screen, SDL_Surface *overlay, SDL_Rect positionOverlay, SDL_Rect Holder1, SDL_Rect Holder2, SDL_Rect Holder3, int arg);
void FillEnigma (enigma Enigma[]);
int Check (int arr[], int Size, int checked);
void Selector (int NoRepeat[], int Size, int *current);
void AnswerSwitch (enigma Enigma[], SDL_Rect *positionAnswer1, SDL_Rect *positionAnswer2, SDL_Rect *positionAnswer3, int current);
void EndScreen (SDL_Surface *screen, SDL_Surface *overlay, SDL_Rect position, SDL_Rect positionOverlay, Mix_Chunk *son, int attempts, int *retry);


#endif // ENIGMA_HEADER_H_INCLUDED
