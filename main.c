#include"head.h"


int main(int argc, char *argv[])
{
char *nomfichier="savegame";
int o=0;

personne p;
background b;

p.ij=5;
b.ji=10;

sauvegarder (p,b,nomfichier) ;
o=charger(&p,&b,nomfichier);

}
