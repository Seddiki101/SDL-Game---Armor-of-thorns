#include "function.h"

void initback(Object *backg)
 {
  SDL_WM_SetCaption("scrolling", NULL);
  backg->img=IMG_Load("backg.png") ;
  backg->pos.x=0 ;
  backg->pos.y=0 ;
}

void setup (SDL_Surface *ecran, Object *backg ) 
{
  SDL_BlitSurface(backg->img,NULL,ecran, &(backg->pos));

  SDL_Flip(ecran) ;
}


void initialisation_e_s(EntiteS t[]) {
    int i;
    for(i=0; i<3; i++)
    {
        t[i].num=1;
        t[i].speed=5;
        t[i].follow=0;
        t[i].imageES[1]=IMG_Load("monster left.png");
        t[i].imageES[0]=IMG_Load("monster right.png");
        t[i].xmin=1200+(500*i);
        t[i].xmax=1500+(500*i);
        t[i].posES.w=t[i].imageES[0]->w/4;
        t[i].posES.h=t[i].imageES[0]->h;
        t[i].posES.x=t[i].xmin;
        t[i].posES.y=600;
        t[i].d=0;
	t[i].spriteES.w=t[i].imageES[0]->w/4;
	t[i].spriteES.h=t[i].imageES[0]->h;
	t[i].spriteES.y=0;
    }
}
void affichage_entites_secondaires(EntiteS t[],SDL_Surface *ecran, Object backg )
{
printf("boobies2\n");
    int i;
    for(i=0; i<3; i++)
        if(t[i].num>-1)
{printf("boobies3\n");
SDL_BlitSurface(backg.img,NULL,ecran, &backg.pos);
printf("boobies4\n");
            SDL_BlitSurface(t[i].imageES[t[i].d],&t[i].spriteES, ecran, &t[i].posES);
 SDL_Flip(ecran) ;
}
}



void animation_e_s(EntiteS t[]) 
{
    int i;
    SDL_Rect spriteES;
    for(i=0; i<3; i++) {
        if(t[i].num>-1) {
            if(t[i].num<3)
                t[i].num++;
            else
                t[i].num=0;
        }
    t[i].spriteES.x=t[i].num*t[i].spriteES.w;}
}
int bounding_box(SDL_Rect t1,SDL_Rect t2)
{
    if ((t1.x>t2.x)&&(t1.x<t2.x+t2.w)&&(t1.y>t2.y)&&(t1.y<t2.y+t2.h))
        return 1;
    if ((t1.x+t1.w>t2.x)&&(t1.x+t1.w<t2.x+t2.w)&&(t1.y>t2.y)&&(t1.y<t2.y+t2.h))
        return 1;
    if ((t1.x+t1.w>t2.x)&&(t1.x+t1.w<t2.x+t2.w)&&(t1.y+t1.h>t2.y)&&(t1.y+t1.h<t2.y+t2.h))
        return 1;
    if ((t1.x>t2.x)&&(t1.x<t2.x+t2.w)&&(t1.y+t1.h>t2.y)&&(t1.y+t1.h<t2.y+t2.h))
        return 1;
    return 0;
}
 void gestion_pos_e_s(EntiteS t[])
{
    int i;
    for(i=0; i<3; i++)
        if(t[i].follow==0)
        {
            if(t[i].d==0)
            {
                if(t[i].posES.x+t[i].posES.w<t[i].xmax)
                    t[i].posES.x=t[i].posES.x;
                else
                    t[i].d=1;
            }
            if(t[i].d==1)
            {
                if(t[i].posES.x>t[i].xmin)
                    t[i].posES.x=t[i].posES.x;
                else
                    t[i].d=0;
            }
        }
}
 void deplacement_alea(EntiteS dep) 
{
    float x;
    x=dep.posES.x;
    x=x/125 -5.65;
    if(dep.posES.x%200==0)
        dep.dea=rand()%2;
    if(dep.dea==0)
    {
        if(dep.posES.x+dep.posES.w<1400)
            dep.posES.x=dep.posES.x+dep.speed;
        else
            dep.dea=1;
    }
    if(dep.dea==1)
    {
        if(dep.posES.x>40)
            dep.posES.x=dep.posES.x-dep.speed;
        else
            dep.d=0;
    }

}

