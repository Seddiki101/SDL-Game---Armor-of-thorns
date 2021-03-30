/**
* @file map.c
*/


/**
* @brief To initialize the minimap m .
* @param m the minimap
* @param screen of the image
* @return Nothing
*/

/*il faut l include du perso pour que sa marche */
#include "perso.h"
#include "map.h"


void initmap (minimap *m,SDL_Surface *screen)
{
m->minimap=IMG_Load("");
/*changer les dimension*/
m->minimap_pos.x = 80;
m->minimap_pos.y = 700;

m->mini_perso=SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_DOUBLEBUF,15,15,32,0,0,0,0);
SDL_FillRect(m->mini_perso,NULL,SDL_MapRGB(screen->format,0,0,255));
m->pos_perso_map.x=0;
m->pos_perso_map.y=0;

m->mini_entite=SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_DOUBLEBUF,15,15,32,0,0,0,0);
SDL_FillRect(m->mini_entite,NULL,SDL_MapRGB(screen->format,255,0,0));
m->pos_entite_map.x=0;
m->pos_entite_map.y=0;

}






/**
* @brief To show the map .
* @param scren the screen
* @param m the map
* @return Nothing
*/


void afficherminimap(map *m , SDL_Surface *screen,entite *e){
    
      SDL_BlitSurface(m->map, NULL, screen,&m->map_pos);
 if(e->affiche)
      SDL_BlitSurface(m->mini_perso, NULL, screen,&m->pos_perso_map);
      SDL_BlitSurface(m->mini_entite, NULL, screen,&m->pos_entite_map);

}





void mise_a_jour_map(map *m , SDL_Surface *screen, perso *p, entite *e)
{
  perso_map(m,p);
  entite_map(m,e);
  afficheminimap(m,screen,e);
}






void Timer(int *tempsdebut)
{
    
   if( SDL_GetTicks() - *tempsdebut >= 1000 )
    {
        *tempsdebut = SDL_GetTicks() ;
      
      
    }
  
}
/**
* @brief To initialize the time .
* @param time t
* @return Nothing
*/
void inittemps(Time *t)
{   int test; 
	t->tempsdebut=0;
	t->mm=0;
	t->ss=0;
	test=initTexttime(&t->temps);
}
/**
* @brief To initialize the text of time .
* @param Text  T
* @return testload
*/

int initTexttime(Text* T)
{ int testload;
    T->coulTxt.r = 255; 
    T->coulTxt.g = 255; 
    T->coulTxt.b = 255;

    strcpy(T->txt, "");
    T->posText.x = 200;
    T->posText.y = 100; 
    testload=loadFonttime(T,"arial.ttf");
    T->textSur=NULL;
    return testload;   
}
/**
* @brief To load Font time .
* @param Text T
* @param path char 
* @return 0 or -1
*/
int loadFonttime(Text* T, char* path)
{
    TTF_Font* police = NULL;

    if(TTF_Init() == -1) {
        printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        return -1;
    }
    T->poli= TTF_OpenFont(path,60);
    if (T->poli == NULL) {
        printf("Unable to load Font: %s\n", SDL_GetError());
        return (-1);
    }
    return (0);
}
/**
* @brief To update time .
* @param Time T 
* @return nothing
*/

void update_time(Time* T)
{   int ts;
    Timer(&T->tempsdebut);
    ts=T->tempsdebut/1000;
    T->mm=ts/ 60;
    T->ss=ts % 60;
    printf("ts : %d , mm : %d , ss : %d\n\n",ts,T->mm,T->ss);
    sprintf(T->temps.txt,"time :%d:%d",T->mm,T->ss);
    T->temps.textSur=TTF_RenderText_Solid(T->temps.poli,T->temps.txt,T->temps.coulTxt);
}
/**
* @brief To display time  .
* @param Time T 
* @param screen  
* @return nothing (void)
*/
void affichertime(Time T,SDL_Surface *screen)
{
    
     
     SDL_BlitSurface(T.temps.textSur,NULL,screen,&(T.temps.posText));

}
/**
* @brief To free the Text for time .
* @param Text T
* @return nothing
*/


void freeTexttime(Text T)
{
    TTF_CloseFont(T.poli); 
    TTF_Quit();    
}


/**
* @brief To do the collision bonding box .
* @param e the entite
* @param p the character
* @return 1 ou 0
*/



int collisionPP(perso *p, entite *e)
{
  
    if ((p->position_perso.x >= e->entite_pos.x + e->entite_pos.w) || (p->position_perso.x + p->position_perso.w <= e->entite_pos.x) || (p->position_perso.y >= e->entite_pos.y + e->entite_pos.h) || (p->position_perso.y + p->position_perso.h <= e->entite_pos.y)
    )
        return 0;

    else
        return 1;
}













