  /**--------------------------------------------------------**/
  /**       C o n v e r s i o n   Z vers C (Standard)        **/
  /**             R�alis�e par Pr D.E ZEGOUR                 **/
  /**             E S I - Alger                              **/
  /**             Copywrite 2014                             **/
  /**--------------------------------------------------------**/


  /*********************************  Les variables ************************************/

  #include <stdio.h>
  #include <stdlib.h>
  #include <Time.h>
  #include <math.h>


  typedef int bool ;

  #define True 1
  #define False 0

  /** Impl�mentation **\: ARBRE BINAIRE DE ENTIERS**/

  /** Arbres de recherche binaire **/

  typedef int Typeelem_Ai   ;
  typedef struct Noeud_Ai * Pointeur_Ai ;

  struct Noeud_Ai
    {
      Typeelem_Ai  Val ;
      Pointeur_Ai Fg ;
      Pointeur_Ai Fd ;
      Pointeur_Ai Pere ;
     } ;

  Typeelem_Ai Info_Ai( Pointeur_Ai P )
    { return P->Val;   }

  Pointeur_Ai Fg_Ai( Pointeur_Ai P)
    { return P->Fg ; }

  Pointeur_Ai Fd_Ai( Pointeur_Ai P)
    { return P->Fd ; }

  Pointeur_Ai Pere_Ai( Pointeur_Ai P)
    { return P->Pere ; }

  void Aff_info_Ai ( Pointeur_Ai P, Typeelem_Ai Val)
    {
       P->Val = Val ;
    }

  void Aff_fg_Ai( Pointeur_Ai P, Pointeur_Ai Q)
    { P->Fg =  Q;  }

  void Aff_fd_Ai( Pointeur_Ai P, Pointeur_Ai Q)
    { P->Fd =  Q ; }

  void Aff_pere_Ai( Pointeur_Ai P, Pointeur_Ai Q)
    { P->Pere =  Q ; }

  void Creernoeud_Ai( Pointeur_Ai *P)
    {
      *P = (struct Noeud_Ai *) malloc( sizeof( struct Noeud_Ai))   ;
      (*P)->Fg = NULL;
      (*P)->Fd = NULL;
      (*P)->Pere = NULL;
    }

  void Liberernoeud_Ai( Pointeur_Ai P)
    { free( P ) ; }

  int Aleanombre( int N )
    { return ( rand() % N ); }


  /** Prototypes des fonctions **/

  void Insert (Pointeur_Ai *A , int *X);
  bool  Rech_bst (Pointeur_Ai *A , int *X) ;
  Pointeur_Ai Gen_bst (int *N) ;
 
  /**********************************  Corps des modules **********************************/
  /*inserer dans un arbre A un nouveau element d'info X (acceptant des doubles)*/
  void Insert (Pointeur_Ai *A , int *X)
    {
      /** Variables locales **/
      Pointeur_Ai P=NULL;

      /** Corps du module **/
     if( *A == NULL) {
       Creernoeud_Ai (& *A ) ;
       Aff_info_Ai ( *A , *X ) ;
       Aff_fd_Ai ( *A , NULL ) ;
       Aff_fd_Ai ( *A , NULL ) ;
       }
     else
       {
       if( Info_Ai ( *A ) < *X) {
         P  =  Fd_Ai ( *A ) ;
         Insert ( & P , & *X ) ;
         Aff_fd_Ai ( *A , P ) ;
         Aff_pere_Ai ( P , *A ) ;
         }
       else
         {
         P  =  Fg_Ai ( *A ) ;
         Insert ( & P , & *X ) ;
         Aff_fg_Ai ( *A , P ) ;
         Aff_pere_Ai ( P , *A ) ;

       }
     }
    }
  /*************************  Fonction de recherche dans bst **************************/
  /*retourne vrai si une valeur X existe dans un arbre bst A*/
  bool  Rech_bst (Pointeur_Ai *A , int *X)
    {
      /** Variables locales **/
      bool  Rech_bst2 ;
      bool Bool;
      Pointeur_Ai _Px1=NULL;
      Pointeur_Ai _Px2=NULL;

      /** Corps du module **/
     if( *A == NULL) {
       Bool  =  False ;
       }
     else
       {
       if( Info_Ai ( *A ) < *X) {
         _Px1 =  Fd_Ai ( *A ) ;
         Bool  =  Rech_bst ( &_Px1, & *X ) ;
         }
       else
         {
         if( Info_Ai ( *A ) > *X) {
           _Px2 =  Fg_Ai ( *A ) ;
           Bool  =  Rech_bst ( &_Px2, & *X ) ;
           }
         else
           {
           Bool  =  True ;

         }
       }
     } ;
     Rech_bst2  =  Bool ;

     return Rech_bst2 ;
    }
  /*********************  Fonction qui genere un bst a n data ******************************/
  /*genere un arbre de recherche a N donnees aleatoires */
  Pointeur_Ai Gen_bst (int *N)
    {
      /** Variables locales **/
      Pointeur_Ai Gen_bst2 =NULL;
      int X;
      int I;
      Pointeur_Ai A=NULL;

      /** Corps du module **/
     for( I  =  1 ;I <=  *N ; ++I){
       X  =  Aleanombre(10*(*N)) ;
       while( Rech_bst ( & A , & X )) {
         X  =  Aleanombre(10*(*N)) ;

       } ;
       Insert ( & A , & X ) ;

     } ;
     Gen_bst2  =  A ;

     return Gen_bst2 ;
    }
  
/********************************************************************************************/
// genere le code dot
void genererDotCode(Pointeur_Ai root, FILE* file) {
    if (root == NULL) {
        return;
    }

    if (Fg_Ai(root) != NULL) {
        fprintf(file, "%d -> %d [dir=none];\n",Info_Ai(root),Info_Ai(Fg_Ai(root)));
    }

    if (Fd_Ai(root) != NULL) {
       fprintf(file, "%d -> %d [dir=none];\n",Info_Ai(root),Info_Ai(Fd_Ai(root)));

    }

    genererDotCode(Fg_Ai(root), file);
    genererDotCode(Fd_Ai(root), file);
}
/*************************************************************/
//genere le fichier .png
void dessinBST(Pointeur_Ai root) {
    FILE* file = fopen("bst.dot", "w");
    if (file == NULL) {
        printf("Impossible d'ouvrir le fichier de sortie.\n");
        return;
    }

    fprintf(file, "digraph BST {\n");
    fprintf(file, "    node [shape=circle];\n");

    genererDotCode(root, file);

    fprintf(file, "}\n");

    fclose(file);
    system("dot -Tpng bst.dot -o bst.png");
    printf("L'arbre BST a été dessiné dans le fichier bst.png.\n");
}

/**********************  Program Principal ************************************/

  int main(int argc, char *argv[])
    {
      srand(time(NULL));
      int n=20;
       Pointeur_Ai a1 = Gen_bst(&n);
       dessinBST(a1);
   
      system("PAUSE"); 
           return 0;
    }
/********************** Fin du Program Principal ************************************/
