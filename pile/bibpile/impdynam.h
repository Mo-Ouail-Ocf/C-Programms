 struct maillon {
    int data;
    struct maillon *adr;
 };

 typedef struct maillon *pile;


void creerpile ( pile * pp);
int pilevide (pile p);
int empiler ( pile * pp, int x);
int depiler ( pile *pp, int *x);
void factorisation (int n);
void reverse_pile (pile *pp);
void checkpalind (char t[]);