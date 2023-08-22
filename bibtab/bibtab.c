#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
//--------------------------------------
void lect_tab (int t[], int tai ){
    int i;
    for (i=0;i<tai;i++){
        printf (" T [ %d ] = ",i);
        scanf("%d",&t[i]);
    }
}
//---------------------------------------
void tri_sel ( int t[] , int tai ){
    int min;
    int sauv;
    int i;
    int indact=0;
    int indmin;
    /* a chaque iteration , on cherche l'indice du min du tableau a partir de indact ,
    et puis permuter avec indact*/
    while ( indact < tai-1 ){
         min = t[indact];
         indmin=indact;
        for (i=indact;i<tai;i++){
            if (t[i]<min){
                min =t[i];
                indmin=i;
            }
             }
            sauv = t[indact];
            t[indact]=t[indmin];
            t[indmin]=sauv;
          indact++;

    }
}
//------------------------------
void ecrire_tab (int t[], int tai){
    int i;
    for  (i=0;i<tai;i++){
        printf ("  T[%d] = %d  | " ,i,t[i]);
    }
}
//----------------------------------------------
void insert_tri (int t[], int tai, int val){ //inserer une valeure dans un tableau trie
  int decal=tai-1;
  while ( t[decal]>val ){
     t[decal+1]=t[decal];
     decal--;
  }
  t[decal+1]=val;
}
//------------------------------------------
void suppos_tab (int t[], int  tai, int pos){
    int i;
    for ( i=pos-1;i<tai;i++){
        t[i]=t[i+1];
    }
}
//--------------------------------------------------------
