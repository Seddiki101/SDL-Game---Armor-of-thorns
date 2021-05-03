#include "function.h"
#include "function.c"
int main()
{
SDL_Init(SDL_INIT_VIDEO);
SDL_Surface *ecran = NULL ;
Object backg;
EntiteS dep;
EntiteS t[8];
int running = 1;
SDL_Event event;

ecran = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);


initback(&backg) ;
initialisation_e_s(t);



setup (ecran,&backg) ;




while(running)
{
while(SDL_PollEvent(&event))
{
switch (event.type)
case SDL_QUIT:
     exit(0);
     break;

}
printf("boobies1\n");
affichage_entites_secondaires(t, ecran, backg);
printf("boobies5\n");
animation_e_s( t);
gestion_pos_e_s(t);
deplacement_alea( dep);

}
  return 0;
}
