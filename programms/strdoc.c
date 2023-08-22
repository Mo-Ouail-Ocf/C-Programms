#include <stdio.h>
#include <string.h>

int main() {
//-------------------------------------------
    //  strtok
  /*  char str[] = "Le petit chat est sur le tapis";
    char txt[100];
    strcpy(txt,str); 
    const char delim[] = " ";
    char *token;

    token = strtok(txt, delim);
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, delim);
    }
    printf("%s",str);
 return 0;*/
 //-----------------------------------------
    //strcat concatener 02 chaines
   /* char txt[]="HELLO";
    char txt2[]="WORLD";
    char txt3[50];
    strcpy(txt3,txt);
    strcat(txt3," ");
    strcat(txt3,txt2);
    printf("%s",txt3);*/
//-------------------------------------------------
   //strchr : Cherche la première occurrence d'un caractère dans une chaîne.
   // et renvoit un ptr vers la premier occurence
 /*  char str[] = "Hello, world!";
    char *ptr;

    ptr = strchr(str, ',');

    if (ptr != NULL) {
        printf("Le caractere '%c' a ete trouve a la position %ld de la chaine.\n", *ptr, ptr - str);
    } else {
        printf("Le caractere n'a pas ete trouve dans la chaine.\n");
    }

    return 0;
*/
//------------------------------------------------------
//strstr : Cherche la première occurrence d'une sous-chaîne dans une chaîne.
// et retourne un ptr vers le premier caractere de la chaine
   /*
    char str[] = "Hello, world!";
    char *ptr;

    ptr = strstr(str, "world");

    if (ptr != NULL) {
        printf("La sous-chaine 'world' a ete trouvee dans la chaine a la position %ld.\n", ptr - str);
    } else {
        printf("La sous-chaine n'a pas ete trouvee dans la chaine.\n");
    }

    return 0;
   */
  char txt[100];
  fgets(txt,100,stdin);
  puts(txt);
}

