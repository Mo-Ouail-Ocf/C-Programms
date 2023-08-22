/* ALSDD : Evaluation d'une expression postfixee avec une pile */

#include <stdio.h>
#include <string.h>   // pour strlen ...
//------------------

#define MAXPILE 30

typedef struct {
   int pile[MAXPILE];
   int sommet;
} Tpile;
//----------------------------

void CreerPile( Tpile *p )
{
   p->sommet = 0;      /*  ou alors (*p).sommet = 0   */
}

int PilePleine( Tpile p )
{
   return (p.sommet == MAXPILE );
}

int PileVide( Tpile p)
{
   return (p.sommet == 0 );
}

void Empiler( Tpile *p , int val )
{
   if ( !PilePleine( *p ) ) p->pile[ p->sommet++ ] = val;
}

void Depiler( Tpile *p , int *val )
{
   if ( !PileVide( *p ) ) *val = p->pile[ --p->sommet ];
}

void Afficher_Pile( Tpile p )
{
    int i;
    printf("Contenu de la PILE : ");
    for (i=0; i < p.sommet && i < MAXPILE; i++)
        printf(" %d ", p.pile[i]);
    printf("\n\n");
}
//----------------------------


/* pour vérifier si un caractere 'c' est un operateur */
int oper( char c )
{
   if ( c == '+' || c =='-' || c =='*' || c == '/' || c == '~' )
      return 1;
   return 0;
}
  

/* pour vérifier si un operateur 'c' est un binaire */
int binaire( char c )
{
   if ( c != '~' )
      return 1;
   return 0;
}


/* pour calculer le resultat de l'expression: v1 op v2 */
int calcul( char op , int v1 , int v2 )
{
   switch( op ) {
      case '+' : return v1+v2;
      case '-' : return v1-v2;
      case '*' : return v1*v2;
      case '/' : return v1/v2;
   }
   return -1;
}



  // prog. principal: 
   //evalue une chaine representant une expression entiere en postfixee 

int main(  )
{

   char ch[80] = "12 4 ~ 2 - / 24 20 - *";
   
   int i, v1, v2, res;
   
   Tpile p;
   
   printf("Evaluation d'expressions postfixee (ex:%s)\n", ch);
   printf("Donner une exp a evaluer : ");
   fgets(ch , 80 , stdin);
   ch[ strlen(ch)-1 ] = '\0';    // remplacer le retour a ligne par '\0'
   

   // Affichage du contenu du tableau ch ...
   printf("\nExp : |");
   for (i=0; ch[i] != '\0' && i<80; i++)
       printf("_%c_|", ch[i]);
   printf("\n       ");
   for (i=0; ch[i] != '\0' && i<80; i++)    // affichage des indices
       printf("%2d  ", i);
   printf("\n\n");


   CreerPile( &p );
   i = 0;
   while ( ch[i] != '\0' ) {
      if ( oper(ch[i]) ) {   // cas d'un operateur ...
         if ( binaire(ch[i]) ) {
            printf( "operateur binaire : %c a la pos %d dans ch", ch[i] , i );
            Depiler( &p , &v2 );
            Depiler( &p , &v1 );
            res = calcul( ch[i] , v1, v2 );
            Empiler( &p , res );
            printf(" => Depilement de %d et %d puis Empilement de %d\n", \
                    v1, v2, res);            
         }
         else  {    // le cas de l'operateur ~ 'moins uniaire'
            printf( "operateur unaire : %c a la pos %d dans ch", ch[i] , i );
            Depiler( &p , &v1 );
            res = -v1;
            Empiler( &p , res );        
            printf(" => Depilement de %d et Empilement de %d\n", v1, res);
         }
         i++;

         Afficher_Pile( p );
            
      }
      else   // cas d'un operande ou des espaces de separation ...
         if ( ch[i] >= '0' && ch[i] <='9' ) {
            // lire une valeur entiere depuis la chaine: ch+i
            sscanf(ch+i, " %d", &v1);
            printf( "valeur: %d a la pos %d dans ch", v1 , i );
            Empiler( &p , v1 );
            printf(" => Empilement de %d\n", v1);
            // positionner i sur la fin de la valeur lue ...
            while ( ch[i] >= '0' && ch[i] <='9' ) i++;

            Afficher_Pile( p );
            
         }
         else 
            i++;
      
   } // fin du while
   
   // reuperer depuis la pile, le resultat final de l'evaluation
   Depiler( &p , &res );
   printf("Resultat = %d\n", res);

   return 0;
   
}

