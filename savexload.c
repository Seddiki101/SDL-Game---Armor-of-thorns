#include"head.h"

void sauvegarder (personne p, background b, char * nomfichier) 
{

FILE* saVe = NULL;    //we using binary file cuz idk :v
    saVe = fopen(nomfichier,"wb"); // we may change wb+ to wb cuz wb+ adds -> many saves so if it creates a prob , just use a single one meaning wb
 
 if(saVe != NULL) {
 
 fwrite( &p, sizeof(personne), 1, saVe);
 fwrite( &b, sizeof(background), 1, saVe); 
                  
                  } //if
                 
  fclose(saVe);
 
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int charger ( personne * p, background *b , char * nomfichier)
{

FILE* saVe = NULL; 
saVe = fopen(nomfichier,"rb");
if(saVe != NULL) {

fread(&(*p), sizeof(personne), 1, saVe);
fread(&(*b), sizeof(background), 1, saVe);

            printf("test ahawa %d  %d ",p->ij,b->ji);      
                 }
fclose(saVe);
return 0; 
                 
}

