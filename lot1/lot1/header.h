#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct
{
	SDL_Surface * sheet,*photo_vie,*photo_score;
	int imgNum;
	SDL_Rect position;
SDL_Color Noir;
TTF_Font *police;

  SDL_Rect posSprite,position_vie,position_score;
  int direction; // 0 RIGHT 1 LEFT
  int score,vie;
  
}perso;



void initPerso(perso *p);
void afficherPerso(perso p, SDL_Surface * screen);
void animerPerso( perso * p);
void deplacer( perso *p);



SDL_Surface * SDL_initialize( int largeur, int hauteur);
