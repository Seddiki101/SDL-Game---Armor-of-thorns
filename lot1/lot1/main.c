#include "header.h"

int  main()
{
	SDL_Surface* screen;


screen=SDL_initialize(1277,720);

	SDL_Surface *background=IMG_Load("background0.PNG");
	SDL_Rect position_background;

position_background.x=0;
position_background.y=0;

perso p;
initPerso(&p);

int continuer=1;
while(continuer) //game loop
{
		SDL_BlitSurface(background,NULL,screen,&position_background);
    afficherPerso(p,screen);
    deplacer(&p);
    animerPerso(&p);
SDL_Event event;



if (SDL_PollEvent(&event)!=0)
{
	if (event.type==SDL_KEYDOWN)  //mouse clic event
	{
		if (event.key.keysym.sym==SDLK_RIGHT)
			p.direction=0;
                if (event.key.keysym.sym==SDLK_LEFT)
                        p.direction=1;		
			
	}
	if (event.type==SDL_KEYUP)
	{
		if (event.key.keysym.sym==SDLK_RIGHT)
			p.direction=-1;
                 if (event.key.keysym.sym==SDLK_LEFT)
                        p.direction=-1;
				
	}

}//fin if


if (p.direction==0)
p.score+=10;


  SDL_Flip(screen);
}






}//fin main
