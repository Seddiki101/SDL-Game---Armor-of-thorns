#ifndef MENU_HEADER_H_INCLUDED
#define MENU_HEADER_H_INCLUDED

// Previously modified by :
//
// Last modified by : ilyes
//
// 230053 is funny. Funny numbers go brrrrrrrrrrrrrrrrr


#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>


void DrawOverlay (SDL_Surface *screen, SDL_Surface *overlay, SDL_Rect positionOverlay, SDL_Rect Holder1, SDL_Rect Holder2, SDL_Rect Holder3, int arg);
int DrawMenu (SDL_Surface *screen, SDL_Rect position, int arg);
int AskConfirmationQuit (SDL_Surface *screen, Mix_Chunk *tick, int *running);
int OptionMenu (SDL_Surface *screen, Mix_Chunk *tick, int *fullscreen);
void GIFloader (char prefix[], char suffix[], SDL_Surface *screen, SDL_Rect position, int maximum, int repeat);
void GIFloaderBuffer (char prefix[], char suffix[], SDL_Surface *screen, SDL_Rect position, int *buffer, int *i, int maximum);


#endif // MENU_HEADER_H_INCLUDED
