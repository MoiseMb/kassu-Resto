#include <stdio.h>
#include "Mbengue_library.c"

// toute les fonctions et procedures appelles se trouve dans le fichier 'Mbengue_library.c'



int main(int argc, char const *argv[])
{
	char simba[6];
	;

	file *notre_file=malloc(sizeof(notre_file)); //on declare la file
	initiale(notre_file); //on initialise le nombre de noeud a zero

	//cette boucle sert a compté le nombre de client
	do{
	inserer(notre_file);
	printf("\avotre commande a été prise en compte \n");
	printf("\tpatienter 5min en attendant que nous preparons votre commande       \n\n");
	printf("\tKASSU vous remercie pour votre confiance\n\n");
	printf("Vous pouver laisser la place au prochain client pousseul fi nk\n");
	printf("ki si top na nieuw\n");

	affichage(notre_file); //cette affichage montre la commande client et prix


	printf("voulez vous passer une commande taper oui pour continuer\n");
	getchar();
	scanf("%s",simba);
	
	}while(strcmp(simba,"oui")==0);

	affichage(notre_file); //une fois qu'il y a plus de client om parcoure toute la file pour 
	                       //Ainsi tout affichers et chaque 5min on defile 
	return 0;
}