#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#define MAX 100


typedef struct {
    int tab[MAX];
    int tete , queue;
    }file;


//-------------------------------
void creerfile ( file *pf){
    pf->tete=MAX-1;
    pf->queue=MAX-1;
}
//------------------------------
int filevide (file f){
    return (f.tete==f.queue);
}
//-----------------------------------------
int fileplein (file f){
    return ( f.tete == (f.queue +1) % MAX    );
}
//----------------------------------------
int enfiler (int x, file *pf){
    if ( fileplein(*pf))
        return 0;
    pf->queue = (pf->queue+1)% MAX;
    pf->tab[pf->queue]=x;
    return 1;
}
//-------------------------------------------
int defiler (int *x , file *pf){
    if (filevide(*pf))
        return 0;
    pf->tete = (pf->tete+1)%MAX;
    *x = pf->tab[pf->tete];
    return 1;
}
//-------------------------------
int main (){
 file f;
  int x;
    creerfile(&f);
     enfiler(5,&f);
     enfiler(6,&f);
    defiler(&x,&f);
    printf("%d",x);
     
}
