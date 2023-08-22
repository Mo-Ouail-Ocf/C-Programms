#include <stdio.h>
#include <stdlib.h>
 #define MAX 100
typedef struct {
    int t[MAX];
    int sommet;
}pile;

//-------------------------------
void creerpile ( pile * p){
    p->sommet=-1;
}
//--------------------------------
int pilepleine ( pile p){
    return (p.sommet == MAX -1 );
}
//----------------------------
int pilevide ( pile p){
    return (p.sommet==-1);
}
//-------------------------------
int empiler  ( pile* ptr , int data){
    if (pilepleine(*ptr)) return 0;
    (ptr->sommet)++;
    ptr->t[ptr->sommet ]=data;
    return 1 ;
}
//------------------------------------
int depiler ( pile *ptr ,int *x){
    if (pilevide(*ptr)) return 0;
    *x = ptr->t[ ptr->sommet  ];
    ptr->sommet--;
    return 1;
}
//----------------------
void reverse_pile (pile *pp){

 pile p1,p2;
 creerpile(&p1);
 creerpile(&p2);
 int &x;
 while (*pp !=NULL){
   depiler(pp,&x);
   empiler(&p1,x);
 }
 while (p1 !=NULL){
    depiler(&p1,&x);
   empiler(&p2,x);
 }
 while ( p2 != NULL){
    depiler(&p2,&x);
     empiler(pp,x);
 }

}
//--------------------
int main (){
   char t[100];
   t="hello how are u";  
}