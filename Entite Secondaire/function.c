#include "function.h"




void initialisation_e_s(test t[8])
{
    int i;
    for(i=0; i<3; i++)
    {
        t[i].num=1;
        t[i].speed=5;
        t[i].follow=0;
        t[i].imageES[1]=IMG_Load("entite/monster left.png");
        t[i].imageES[0]=IMG_Load("entite/monster right.png");
        t[i].xmin=1200+(500*i);
        t[i].xmax=1500+(500*i);
        t[i].posES.w=t[i].image[0]->w/4;
        t[i].posES.h=t[i].image[0]->h;
        t[i].posES.x=t[i].xmin;
        t[i].posES.y=600;
        t[i].d=0;
	t[i].spriteES.w=t[i].image[0]->w/4;
	t[i].spriteES.h=t[i].image[0]->h;
	t[i].spriteES.y=0;
    }
}
void affichage_entites_secondaires(ES t[8],SDL_Surface *ecran)
{
    int i;
    for(i=0; i<3; i++)
        if(t[i].num>-1)
            SDL_BlitSurface(t[i].imageES[t[i].d],&t[i].spriteES, ecran, &t[i].posES);
}


void gestion_pos_e_s(ES t[8],perso p)
{
    int i;
    for(i=0; i<3; i++)
        if(t[i].follow==0)
        {
            if(t[i].d==0)
            {
                if(t[i].posES.x+t[i].posES.w<t[i].xmax)
                    t[i].posES.x=t[i].posES.x+t[i].speed;
                else
                    t[i].d=1;
            }
            if(t[i].d==1)
            {
                if(t[i].posES.x>t[i].xmin)
                    t[i].posES.x=t[i].pos.x-t[i].speed;
                else
                    t[i].d=0;
            }
        }
}
void animation_e_s(test t[8])
{int i;SDL_Rect crop;
    for(i=0; i<3; i++)
{if(t[i].num>-1){if(t[i].num<3) t[i].num++;else t[i].num=0;}
t[i].crop.x=t[i].num*t[i].crop.w;}
}
void dep_alea(ES dep)
{
    float x;
    x=b.pos.x;
    x=x/125 -5.65;
    if(b.posES.x%200==0)
        b.dea=rand()%2;
    if(b.dea==0)
    {
        if(b.posES.x+b.posES.w<1400)
            b.posES.x=b.posES.x+b.speed;
        else
            b.dea=1;
    }
    if(b.dea==1)
    {
        if(b.posES.x>40)
            b.posES.x=b.posES.x-b.speed;
        else
            b.d=0;
    }
    return b;
}

