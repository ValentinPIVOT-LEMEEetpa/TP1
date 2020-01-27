#include <stdio.h>
#include <stdlib.h>


int vie = 100;
int maVie = 100;

int armes = 40;
int mains = 5;

int bouclier = 10;
int etatBouclierJoueur = 0;
int etatBouclierAdverse = 0;

int mana = 10;
int manaAdverse=10;

int choix;
int nombre = 0;

int poison = 0;
int sonPoison = 0;

int antidote = 0;
int antidoteAdverse = 0;

int comptTours = 0;

const int MIN = 1, MAX = 3;


int main(void){
	srand(time(NULL)); // Initialisation de la donnée seed
	

	while(vie >=1 && maVie >=1){
		printf("---------------------------------------\n");
		comptTours = comptTours +1;
		printf("Tours numero : %d \n", comptTours);
		printf("sa vie:%d \n", vie);
		printf("son mana:%d\n", manaAdverse);
		printf("ma vie:%d\n", maVie);
		printf("mon mana:%d \n", mana);
		if(vie >=1){
			printf("-----------------------------------------------\n");
			printf("-------------------son tour--------------------\n");
			if(manaAdverse != 10){
				printf("Mon adversaire est a %d de mana\n", manaAdverse );
			}

			if(poison==1){
				vie=vie-10;
			}

			printf("\n");
			nombre = (rand() % (MAX + 1 - MIN)) + MIN; // MIN <= nombre <= MAX
			   
			printf("l'ennemi a choisi %d \n", nombre);
			   
			if (nombre== 1){
				if (etatBouclierJoueur == 0){
					maVie = maVie-armes;
					printf("J'ai pris un coup !\n", maVie);
					printf("Ma vie est de :%d\n", maVie);
				}else if (etatBouclierJoueur == 1){
					maVie = maVie- (armes/4);
					printf("Ma vie est de :%d\n", maVie);
				}
			}else if (nombre== 2){
				etatBouclierAdverse = 1;
				printf("l'adversaire s'est mit en parade \n");
			}else if(nombre==3){
				if(manaAdverse>=5){
					printf("L'advairsaire attaque avec du poison\n");
					sonPoison=1;
					manaAdverse=manaAdverse-5;
				}else if(manaAdverse <= 0){
					printf("Comme il ne peut plus utiliser de mana, il relance un chiffre\n");
					printf("\n");
					nombre = (rand() % (2 + 1 - 1)) + 1; // MIN <= nombre <= MAX
			   
					printf("l'ennemi a choisi %d \n", nombre);
			   
					if (nombre== 1){
						if (etatBouclierJoueur == 0){
							maVie = maVie-armes;
							printf("J'ai pris un coup !\n", maVie);
							printf("Ma vie est de :%d\n", maVie);
						}else if (etatBouclierJoueur == 1){
							maVie = maVie - (armes/4);
							printf("Ma vie est de :%d\n", maVie);
						}
					}else if (nombre== 2){
						etatBouclierAdverse = 1;
						printf("l'adversaire s'est mit en parade \n");
					}
				}
			}
		}
		printf("\n");
		printf("-----------------------------------------------\n");
		printf("-------------------mon tour--------------------\n");
		if(mana != 10){
			mana = mana+1;
		}

		if(sonPoison==1){
			maVie=maVie-10;
			printf("\n");
			printf("Je me suis pris un coup par du poison. Je perd 10 points de vie\n");
			printf("ma vie est de :%d\n", maVie);
		}
		if(maVie >= 1){
			printf("\n");
			printf("J'ai le choix entre 4 possibilites. La premieres et d'attaquer (1), la deuxieme et de me defendre(2) ,la troisieme de lance un sort poison(3) et la quatrieme est d'utiliser un entidote contre le poison(4).\n");
			printf("\n");
			printf("L'attaque au poison coute 5 point de mana\n");
			printf("\n");
			printf("L'antidote coute 3 de mana\n");
			printf("\n");
			printf("J'ai %d points de mana\n", mana);
			printf("\n");
			printf("Mon choix:");
			scanf("%d",&choix);


			if (choix== 1){
				if(etatBouclierAdverse==1){
						vie = vie - (armes/4);
						printf("l'adversaire s'est proteger, il recoit un quart de ce que je lui inflige\n");
				}
				else if(etatBouclierAdverse==0){
					vie=vie-armes;
					printf("Sa vie est de :%d\n", vie);
				}
			}else if (choix== 2){
				etatBouclierJoueur = 1;
				printf("Je me suis en parade \n");
			}else if (choix== 3){
				if(mana>= 5){
						printf("Je peux attaquer avec le poison.YES!\n");
						poison=1;
						mana=mana-5;
				}
				else{
					printf("Je ne peux pas, je ne peux que attaquer avec une armes ou me defendre\n");
					scanf("%d",&choix);
				}
			}
			else if (choix == 4){
				if(sonPoison==1){
					sonPoison=0;
					mana=mana-3;
				}
				else{
					printf("Je ne peux pas utiliser l'antidote parce que je ne suis pas empoisonner. Je viens de gacher un tour pour rien.\n");
				}
			}
		}
		if(vie<=0){
			printf("J'ai gagne!!! Je suis trop fort!\n");
		}
		if(maVie<=0){
			printf("Arf. j'ai perdu. Je reviendrais plus fort\n" );
		}
	}
}