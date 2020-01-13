#include <stdio.h>


int vie=100;

int armes=5;
int poison= 15;
int mains= 1;

int main(){
printf("vie:%d\n", vie);
while(vie!=0){

printf("\n");
printf("Tu t'es pris un coup par une arme\n");
	vie= vie-armes;

printf("vie:%d\n", vie);
};

return 0;
}