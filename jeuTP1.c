#include <stdio.h>


int vie=100;
int maVie=100;

int armes=5;
int poison= 15;
int mains= 1;

int main(){
printf("sa vie:%d\n", vie);
printf("ma vie:%d\n", maVie);

while(vie >0 && maVie >0){

printf("\n");
printf("Tu t'es pris un coup par une arme. Tu pers %d points de vie\n" , armes);
	vie= vie-armes;

printf("Sa vie est de:%d\n", vie);

printf("\n");
printf("Je me suis pris un coup par une arme. Je pers %d points de vie\n" , poison);
	maVie= maVie-poison;

printf("ma vie est de :%d\n", maVie);
};




return 0;



}