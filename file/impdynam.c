#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
 
 struct maillon {
    int val;
    struct maillon *adr;
 };
typedef struct {
    struct maillon *tete , *queue;
 }file;
//--------------------------------
 void creerfile ( file *pf){
     pf->tete =NULL;
     pf->queue = NULL;
 }
//----------------------------------
int filevide ( file f){
    return ( f.tete==NULL);
}
//--------------------------------
int enfiler (int x ,file *pf ){
    struct maillon *p;
    p=malloc(sizeof(*p));
    p->val=x;
    p->adr=NULL;
    if (pf->queue)
        pf->queue->adr = p;
    else
        pf->tete = p;
     pf->queue = p;
        return 1;
 }
 //----------------------------------
 int defiler (int *x,file *pf){
  struct maillon *p;
    if (filevide(*pf))
   return 0;
    *x = pf->tete->val;
    p=pf->tete;
    pf->tete = pf->tete->adr;
    free(p);
    if (pf->tete==NULL)
        pf->queue= NULL;
        return 1;
    }
 //------------------------------------
     
 
 void main (){
    file f;
    int x;
    creerfile(&f);
     enfiler(5,&f);
     enfiler(6,&f);
    defiler(&x,&f);
    printf("%d",x);
     defiler(&x,&f);
 
 }