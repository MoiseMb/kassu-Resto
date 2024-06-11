#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	char nom_plat1[30];
	char nom_plat2[30];
	int quantite1;
	int quantite2;
	int prix1;
	int prix2;

} informa;

typedef struct
{
	informa entrer;
	informa resistance;
	informa dessert;
} commande;

typedef struct client client;

struct client
{
	commande cliente;
	client *suivant;
};
typedef struct file
{

	client *debut;
	client *fin;
	int taille;
} file;
void initiale(file *format)
{
	format->debut = NULL;
	format->fin = NULL;
	format->taille = 0;
}

int controle(int valeur, int nombre_max)
{
	while (valeur > nombre_max)
	{
		printf("Erreur %d ne correspond a aucun des choix \nveuillez saisir a nouveau\n", valeur);
		scanf("%d", &valeur);
	}

	return valeur;
}

void inserer(file *simba)
{
	int choix, choix_perso;

	client *contenu = malloc(sizeof(*contenu));

	char commande1[7], test[7];
	printf("\t\t\tBienvenue dans le restaurant KASSU\n\n\n");
	contenu->cliente.entrer.quantite1 = 0;
	contenu->cliente.entrer.quantite2 = 0;
	contenu->cliente.resistance.quantite1 = 0;
	contenu->cliente.resistance.quantite2 = 0;
	contenu->cliente.dessert.quantite1 = 0;
	contenu->cliente.dessert.quantite2 = 0;

	do
	{
		printf("\tveuillez choisir une categorie\n");
		printf("\t****************************\n");
		printf("\t*          1.ENTRER        *\n");
		printf("\t****************************\n");
		printf("\t*          2.RESISTANCE    *\n");
		printf("\t****************************\n");
		printf("\t*          3.DESSERT       *\n");
		printf("\t****************************\n");
		scanf("%d", &choix);
		choix = controle(choix, 3);
		if (choix == 1)
		{
			do
			{
				printf("\t*******************************************\n");
				printf("\t*       Menu entrer        |       prix   *\n");
				printf("\t*******************************************\n");
				printf("\t*  1.croissant jambon      |       2000   *\n");
				printf("\t*******************************************\n");
				printf("\t*  2.pain omelette         |       1500   *\n");
				printf("\t*******************************************\n");
				printf("taper '1' ou '2' pour choisir l element \n");
				scanf("%d", &choix_perso);
				choix_perso = controle(choix_perso, 2);
				if (choix_perso == 1)
				{
					strcpy(contenu->cliente.entrer.nom_plat1, "croissant jambon");
					printf("combien en voulez vous ?\n");
					scanf("%d", &contenu->cliente.entrer.quantite1);
					contenu->cliente.entrer.prix1 = 2000;
				}
				else
				{
					strcpy(contenu->cliente.entrer.nom_plat2, "pain omelette");
					printf("combien en voulez vous ?\n");
					scanf("%d", &contenu->cliente.entrer.quantite2);
					contenu->cliente.entrer.prix2 = 1500;
				}
				printf("voulez vous commander un suppliments saisir 'oui' pour confirmer et 'non' pour quitter ce Menu\n");
				getchar();
				scanf("%s", commande1);

			} while (strcmp(commande1, "oui") == 0);
		}
		else
		{

			if (choix == 2)
			{
				do
				{
					printf("\t*******************************************\n");
					printf("\t*       Menu resistance    |      prix    *\n");
					printf("\t*******************************************\n");
					printf("\t*        1.PAELLA          |      20000   *\n");
					printf("\t*******************************************\n");
					printf("\t*        2.THIEBOU GUANAR  |      15000   *\n");
					printf("\t*******************************************\n");
					printf("taper '1' ou '2' pour choisir l element \n");
					scanf("%d", &choix_perso);
					choix_perso = controle(choix_perso, 2);
					if (choix_perso == 1)
					{
						strcpy(contenu->cliente.resistance.nom_plat1, "PAELLA");
						printf("combien en voulez vous ?\n");
						scanf("%d", &contenu->cliente.resistance.quantite1);
						contenu->cliente.resistance.prix1 = 20000;
					}
					else
					{
						strcpy(contenu->cliente.resistance.nom_plat2, "THIEBOU GUANAR");
						printf("combien en voulez vous ?\n");
						scanf("%d", &contenu->cliente.resistance.quantite2);
						contenu->cliente.resistance.prix2 = 15000;
					}
					printf("voulez vous commander un suppliments saisir 'oui' pour confirmer et 'non' pour quitter ce Menu\n");
					getchar();
					scanf("%s", commande1);

				} while (strcmp(commande1, "oui") == 0);
			}
			else

			{
				do
				{
					printf("\t*******************************************\n");
					printf("\t*       Menu Dessert     |       prix     *\n");
					printf("\t*******************************************\n");
					printf("\t*  1.Milk shake          |       5000     *\n");
					printf("\t*******************************************\n");
					printf("\t*  2.tiramisu            |      10000     *\n");
					printf("\t*******************************************\n");
					printf("taper '1' ou '2' pour choisir l element \n");
					scanf("%d", &choix_perso);
					choix_perso = controle(choix_perso, 2);
					if (choix_perso == 1)
					{
						strcpy(contenu->cliente.dessert.nom_plat1, "Milk SHake");
						printf("combien en voulez vous ?\n");
						scanf("%d", &contenu->cliente.dessert.quantite1);
						contenu->cliente.dessert.prix1 = 5000;
					}
					else
					{
						strcpy(contenu->cliente.dessert.nom_plat2, "tiramisu");
						printf("combien en voulez vous ?\n");
						scanf("%d", &contenu->cliente.dessert.quantite2);
						contenu->cliente.dessert.prix2 = 10000;
					}
					printf("voulez vous commander un suppliments saisir 'oui' pour confirmer et 'non' pour quitter ce Menu\n");
					getchar();
					scanf("%s", commande1);

				} while (strcmp(commande1, "oui") == 0);
			}
		}

		printf("voulez vous commander autre chose si oui taper 'oui' Pour vous rediriger vers le menu principale\n");
		printf("sinon taper 'non' pour finaliser la commmande \n");
		getchar();
		scanf("%s", test);

	} while (strcmp(test, "oui") == 0);

	if (simba->taille == 0)
	{
		simba->debut = contenu;
	}
	else
	{
		simba->fin->suivant = contenu;
	}

	simba->fin = contenu;
	contenu->suivant = NULL;
	simba->taille++;
}
void affichage(file *tema)
{

	client *tor = malloc(sizeof(*tor));
	tor = tema->debut;
	int i = 1;
	while (tor != NULL)
	{

		printf("\t\t COMMANDE du client numero %d\n", i);
		printf("********************************************************************\n");
		printf("*       MENU            |     QUANTITE        |     PRIX (cfa)     *\n");
		int prix_total = 0;

		if (strcmp(tor->cliente.resistance.nom_plat1, "PAELLA") == 0)
		{
			printf("********************************************************************\n");
			printf("*   %s 	|       %d 	      |      %d 	         \n", tor->cliente.resistance.nom_plat1, tor->cliente.resistance.quantite1, tor->cliente.resistance.prix1);
			prix_total += tor->cliente.resistance.prix1 * tor->cliente.resistance.quantite1;
		}
		if (strcmp(tor->cliente.resistance.nom_plat2, "THIEBOU GUANAR") == 0)
		{
			printf("********************************************************************\n");
			printf("*   %s 	|       %d 	      |      %d 	     \n", tor->cliente.resistance.nom_plat2, tor->cliente.resistance.quantite2, tor->cliente.resistance.prix2);
			prix_total += tor->cliente.resistance.prix2 * tor->cliente.resistance.quantite2;
		}
		if (strcmp(tor->cliente.entrer.nom_plat1, "croissant jambon") == 0)
		{
			printf("********************************************************************\n");
			printf("*   %s 	|       %d 	      |      %d 	         \n", tor->cliente.entrer.nom_plat1, tor->cliente.entrer.quantite1, tor->cliente.entrer.prix1);
			prix_total += tor->cliente.entrer.prix1 * tor->cliente.entrer.quantite1;
		}
		if (strcmp(tor->cliente.entrer.nom_plat2, "pain omelette") == 0)
		{
			printf("********************************************************************\n");
			printf("*   %s 	|       %d 	      |      %d 	     \n", tor->cliente.entrer.nom_plat2, tor->cliente.entrer.quantite2, tor->cliente.entrer.prix2);
			prix_total += tor->cliente.entrer.prix2 * tor->cliente.entrer.quantite2;
		}
		if (strcmp(tor->cliente.dessert.nom_plat1, "Milk SHake") == 0)
		{
			printf("********************************************************************\n");
			printf("*   %s 	  |       %d 	       |     %d 	       \n", tor->cliente.dessert.nom_plat1, tor->cliente.dessert.quantite1, tor->cliente.dessert.prix1);
			prix_total += tor->cliente.dessert.prix1 * tor->cliente.dessert.quantite1;
		}
		if (strcmp(tor->cliente.dessert.nom_plat2, "tiramisu") == 0)
		{
			printf("********************************************************************\n");
			printf("*   %s 	|       %d 	      |      %d 	      \n", tor->cliente.dessert.nom_plat2, tor->cliente.dessert.quantite2, tor->cliente.dessert.prix2);
			prix_total += tor->cliente.dessert.prix2 * tor->cliente.dessert.quantite2;
		}
		printf("********************************************************************\n");
		printf("*        prix total de la commande   :    %d                      \n", prix_total);
		printf("********************************************************************\n\n");
		printf("patienter 5min en attendant que nous preparons votre commande       \n\n");
		printf("KASSU vous remercie pour votre confiance\n\n");
		i++;
		tor = tor->suivant;
	}