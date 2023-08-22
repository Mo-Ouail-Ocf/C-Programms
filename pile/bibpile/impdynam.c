#include <stdio.h>
#include <stdlib.h>
 #include <string.h>
 #include <stdbool.h>

 struct maillon {
    int data;
    struct maillon *adr;
 };

 typedef struct maillon *pile;
//--------------------------------
void creerpile ( pile * pp){
    *pp=NULL;
}
//-----------------------------------
int pilevide (pile p){
    return (p==NULL);
}
//--------------------------------
int empiler ( pile * pp, int x){
    pile q = malloc (sizeof (*q));
    q->data=x;
    q->adr = *pp;
    *pp = q;
    return 1;
}
//---------------------------------------
int depiler ( pile *pp, int *x){
    if (pilevide(*pp)) return 0;
    *x = (*pp)->data;
    pile q = (*pp)->adr;
    free(*pp);
    *pp =q;
    return 1;
}
//-----------------------------
 void factorisation (int n){
    pile p;
    int fact=2;
    creerpile(&p);
 while (n != 1){
     while ( n % fact ==0){
        empiler(&p,fact);
        n = n / fact;
     }
    fact++;
  
  while ( !(pilevide(p)) ){
     depiler(&p,&fact);
     printf(" %d | ",fact);
  }
 }
}
//----------------------
void reverse_pile (pile *pp){
int x;
 pile p1,p2;
 creerpile(&p1);
 creerpile(&p2);

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
//----------------------
void checkpalind (char t[]){
    pile p;
    creerpile(&p);
    bool palind;
    int c;
    int i;
    for (i=0;i<strlen(t);i++){
        empiler (&p,t[i]);
    }
    palind=true;
    i=0;
    while ( (palind) && (i<strlen(t) )){
        depiler(&p,&c);
        if ( c != t[i] )
            palind=false;
        i++;
    }
    if (palind)
        printf("PALINDROME !");
    else 
        printf("LA PHRASE N'EST PAS PALINDROME ");
        
    
}

//----------------------
