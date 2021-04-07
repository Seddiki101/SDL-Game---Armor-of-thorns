#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "backgscroll.h"
#include <SDL/SDL_mixer.h>

int main()
{SDL_Init(SDL_INIT_VIDEO);
Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS,1024);
 Mix_Music *musique; //Création du pointeur de type Mix_Music
   

  
SDL_Surface *screen = NULL ;



Objet backg,wood,boat ;
int running=1 ;

 screen= SDL_SetVideoMode(w, h, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);


 

  
  init(&backg) ;
musique = Mix_LoadMUS("musique.mp3"); //Chargement de la musique
Mix_PlayMusic(musique, -1);
setup (screen,&backg) ;


  SDL_EnableKeyRepeat(10, 10);
  while(running){
      event(screen ,&backg,&running  ) ;
     }
    free_back(&backg,musique) ;

    

    return EXIT_SUCCESS;
}
