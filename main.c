
#include"head.h"


int main(int argc, char *argv[])
{

SDL_Surface *screen=NULL;
enigme e;

screen = SDL_SetVideoMode(1280,720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_WM_SetCaption("riddle", NULL);  

char *nomfichier="file.txt";

  genererEnigme(&e,nomfichier);
 
  afficherEnigme(e,screen);
  
}
