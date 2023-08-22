#include <stdlib.h>
#include <stdio.h>
typedef int mat[20][100];

void readmat (int m[][100],int lg,int col){

printf("T[1][2] = " );
scanf("%d",&m[1][2]);
printf("T[1][2] = %d",m[1][2]);
}

int main(){
 mat m;
 readmat(m,3,3);

}