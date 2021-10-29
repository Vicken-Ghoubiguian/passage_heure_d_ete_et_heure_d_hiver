# passage_heure_d_ete_et_heure_d_hiver

Bibliothèque de fonctions de calcul des dates de passage à l'heure d'été et à l'heure d'hiver, et du décalage horaire actuel avec la France, pour plusieurs pays et régions du monde à partir de l'heure et de la date courantes de la timezone __Europe/Paris__.

## Sommaire

1. [Introduction](#introduction)
2. [Présentation](#presentation)
3. [Structure de ce dépôt Git](#structure_de_ce_depot_git)
4. [Comment ce projet a-t-il été développé ?](#comment_ce_projet_a_t_il_ete_developpe)
5. [Comment compiler ce projet après l'avoir cloné depuis GitHub ?](#comment_compiler_ce_projet_apres_l_avoir_clone_depuis_GitHub)
6. [Comment installer cette bibliothèque ?](#comment_installer_cette_bibliotheque)
    * [Linux](#linux)
    * [Mac](#mac)
    * [Windows](#windows)
7. [Comment l'utiliser ?](#comment_l_utiliser)
	* [Intégrée à la bibliothèque standard](#integree)
	* [Non-intégrée à la bibliothèque standard](#non_integree)
8. [Quelques exemples](#quelques_exemples)
9. [Liens utiles](#liens_utiles)
10. [Conclusion](#conclusion)

<a name="introduction"></a>
## Introduction

Va venir...

<a name="presentation"></a>
## Présentation

Va venir...

<a name="structure_de_ce_depot_git"></a>
## Structure de ce dépôt Git

Ce dépôt Git est constitué des éléments suivants:

* __passage_heure_d_ete_et_heure_d_hiver__:
* __.gitignore__:
* __LICENSE__: fichier décrivant la licence de logiciels de cette bibliothèque C
* __README.md__: fichier de presentation et de documentation de cette bibliothéque C ainsi que de tout l'entiéreté de ce projet
* __main.c__: fichier de test de cette bibliothéque

Le dossier __passage_heure_d_ete_et_heure_d_hiver__ correspond au coeur de ce projet.

<a name="comment_ce_projet_a_t_il_ete_developpe"></a>
## Comment ce projet a-t-il été développé ?

Va venir...

<a name="comment_compiler_ce_projet_apres_l_avoir_clone_depuis_GitHub"></a>
## Comment compiler ce projet après l'avoir cloné depuis GitHub ?

1. Tout d'abord, clonez le dépôt Git __passage_heure_d_ete_et_heure_d_hiver__ sur votre ordinateur:
  ```bash
  git clone https://github.com/Vicken-Ghoubiguian/passage_heure_d_ete_et_heure_d_hiver
  ```

2. Rendez vous, ensuite, dans le dépôt cloné sous forme de répertoire:
  ```bash
  cd passage_heure_d_ete_et_heure_d_hiver
  ```

3. Il est temps maintenant de compiler le fichier ```main.c``` avec la bibliothéque ```passage_heure_d_ete_et_heure_d_hiver```.
  Pour ce faire, exécutez la commande suivante:
  ```bash
  gcc main.c passage_heure_d_ete_et_heure_d_hiver/*
  ```
  
  Un fichier exécutable ```a.out``` est généré, il faut l'éxécuter à l'aide de la commande suivante:
  ```bash
  ./a.out
  ```
  
4. Félicitations, maintenant vous pouvez utiliser cette bibliothèque sans problème.

<a name="comment_installer_cette_bibliotheque"></a>
## Comment installer cette bibliothèque ?

<a name="linux"></a>
### Linux

Va venir...

<a name="mac"></a>
### Mac

Va venir...

<a name="windows"></a>
### Windows

Va venir...

<a name="comment_l_utiliser"></a>
## Comment l'utiliser ?

Alors,

<a name="quelques_exemples"></a>
## Quelques exemples

<a name="integree"></a>
### Intégrée à la bibliothèque standard

<a name="non_integree"></a>
### Non-intégrée à la bibliothèque standard

Premier exemple, calcul et affichage du temps UTC (date et heure courante pour tous les fuseaux horaires) grâce à la fonction 'temps_utc_en_struct_tm'...
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "passage_heure_d_ete_et_heure_d_hiver/passage_heure_d_ete_et_heure_d_hiver.h"

// Fonction principale du programme
int main()
{
	//Renvoie de l'horaire actuelle (date et heure systéme) sous forme de timestamp (time_t) grace à la fonction time, sa valeur de retour est affectée à la variable la
	time_t la = time(NULL);

	//Déclaration puis initialisation des variables heure_d_hiver et heure_d_ete sous forme de timestamp (time_t) grace aux fonctions date_du_dernier_dimanche_de_mars et date_du_dernier_dimanche_d_octobre
	time_t heure_d_hiver = date_du_dernier_dimanche_d_octobre(la, 3);
	time_t heure_d_ete = date_du_dernier_dimanche_de_mars(la, 2);

	//Declaration de la variable date_utc qui stocke la valeur du temps UTC (Coordinate Universal Time) sous forme de struct tm
	struct tm *date_utc;

	//Calcul du temps UTC (date et heure) sous forme de struct tm
	date_utc = temps_utc_en_struct_tm(la, heure_d_hiver, heure_d_ete);

	//Saut de ligne (pour la lisibilité)
	printf("\n\n");

	//Affichage du temps universel coordonné (UTC)
	printf("%d:%d:%d - %d %d %d.\n", date_utc->tm_hour, date_utc->tm_min, date_utc->tm_sec, date_utc->tm_mday, date_utc->tm_mon + 1, date_utc->tm_year + 1900);

	//Tout va bien (donc EXIT_SUCCESS)
   	return 0;
}
```
Second exemple, calcul et affichage du temps UTC (date et heure courante pour tous les fuseaux horaires) grâce à la fonction 'temps_utc_en_timestamp'...
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "passage_heure_d_ete_et_heure_d_hiver/passage_heure_d_ete_et_heure_d_hiver.h"

// Fonction principale du programme
int main()
{
	//Renvoie de l'horaire actuelle (date et heure systéme) sous forme de timestamp (time_t) grace à la fonction time, sa valeur de retour est affectée à la variable la
	time_t la = time(NULL);

	//Déclaration puis initialisation des variables heure_d_hiver et heure_d_ete sous forme de timestamp (time_t) grace aux fonctions date_du_dernier_dimanche_de_mars et date_du_dernier_dimanche_d_octobre
	time_t heure_d_hiver = date_du_dernier_dimanche_d_octobre(la, 3);
	time_t heure_d_ete = date_du_dernier_dimanche_de_mars(la, 2);

	//Declaration de la variable temps_utc qui stocke la valeur du temps UTC (Coordinate Universal Time) sous forme de timestamp (time_t), et de la variable date_utc (sous forme de struct tm)
	time_t temps_utc;
	struct tm *date_utc;

	//Calcul du temps UTC (date et heure) sous forme de timestamp
	temps_utc = temps_utc_en_timestamp(la, heure_d_hiver, heure_d_ete);

	//Conversion de la valeur contenue dans la variable temps_utc sous forme de timestamp (time_t) en struct tm grace à la fonction localtime, et affectation du resultat dans la variable date_utc
	date_utc = localtime(&temps_utc);

	//Saut de ligne (pour la lisibilité)
	printf("\n\n");

	//Affichage du temps universel coordonné (UTC)
	printf("%d:%d:%d - %d %d %d.\n", date_utc->tm_hour, date_utc->tm_min, date_utc->tm_sec, date_utc->tm_mday, date_utc->tm_mon + 1, date_utc->tm_year + 1900);

	//Tout va bien (donc EXIT_SUCCESS)
   	return 0;
}
```

exemple, affichage de la date et de l'heure à Seoul (Corée du sud)
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "passage_heure_d_ete_et_heure_d_hiver/passage_heure_d_ete_et_heure_d_hiver.h"

// Fonction principale du programme
int main()
{
	//Renvoie de l'horaire actuelle (date et heure systéme) sous forme de timestamp (time_t) grace à la fonction time, sa valeur de retour est affectée à la variable la
	time_t la = time(NULL);

	// Calcul et retour du temps (la date et l'heure) courant à Séoul sous forme d'une chaine de caractères 
    char* date_et_heure_a_seoul = retour_de_l_heure_et_de_la_date_pour_une_ville_determinee_et_connue(la, "Seoul");

    // Affichage du temps (la date et l'heure) courant à Seoul
    printf("%s\n", date_et_heure_a_seoul);

	//Saut de ligne (pour la lisibilité)
	printf("\n\n");

	//Tout va bien (donc EXIT_SUCCESS)
	return 0;
}
```

 exemple, calcul et affichage de l'horloge complète (date et heure courante pour tous les fuseaux horaires)...
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "passage_heure_d_ete_et_heure_d_hiver/passage_heure_d_ete_et_heure_d_hiver.h"

// Fonction principale du programme
int main()
{
   	//Renvoie de l'horaire actuelle (date et heure systéme) sous forme de timestamp (time_t) grace à la fonction time, sa valeur de retour est affectée à la variable la
	time_t la = time(NULL)
   
   	//Appel à la fonction affichage_de_l_horloge avec comme paramétre le temps courant sous forme d'un timestamp (time_t)
	affichage_de_l_horloge(la);
   
   	//Tout va bien (donc EXIT_SUCCESS)
   	return 0;
}
```

 exemple, calcul et affichage de la date du passage de l'heure d'hiver à l'heure d'été pour tous les fuseaux horaires le pratiquant...
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "passage_heure_d_ete_et_heure_d_hiver/passage_heure_d_ete_et_heure_d_hiver.h"

// Fonction principale du programme
int main()
{
  	//Renvoie de l'horaire actuelle (date et heure systéme) sous forme de timestamp (time_t) grace à la fonction time, sa valeur de retour est affectée à la variable la
	time_t la = time(NULL);

  	//Déclaration puis initialisation des variables heure_d_hiver et heure_d_ete sous forme de timestamp (time_t) grace aux fonctions date_du_dernier_dimanche_de_mars et date_du_dernier_dimanche_d_octobre
	time_t heure_d_hiver = date_du_dernier_dimanche_d_octobre(la, 3);
	time_t heure_d_ete = date_du_dernier_dimanche_de_mars(la, 2);

	//Declaration de la variable temps_utc qui stocke la valeur du temps UTC (Coordinate Universal Time) sous forme de timestamp (time_t)
	time_t temps_utc;

	//Configuration de la variable temps_utc sous forme de timestamp (time_t) correspondant au temps universel coordonné (UTC)
	if(la < heure_d_hiver && la >= heure_d_ete)
	{
		//Le temps universel coordonné est en retard de 2 heures par rapport à l'heure de Paris, celui-ci est affecté à la variable temps_utc
		temps_utc = la - (2 * 3600);
	}
	//Sinon...
	else
	{
		//Le temps universel coordonné est en retard d'1 heure par rapport à l'heure de Paris, celui-ci est affecté à la variable temps_utc
		temps_utc = la - 3600;
	}

  	//Initialisation et affichage des différentes dates de changement heure d'hiver -> heure d'été et réciproquement pour l'Europe, l'Amerique du Nord, l'Australie, le Chili, et la Nouvelle-Zelande
	time_t date_time_t = date_du_dernier_dimanche_de_mars(temps_utc, 2);
	struct tm *date_tm = localtime(&date_time_t);
	printf("Date du dernier dimanche de mars (heure d'hiver -> heure d'été pour l'Europe): %d / %d / %d.\n", date_tm->tm_mday, (date_tm->tm_mon + 1), date_tm->tm_year + 1900);

	date_time_t = date_du_dernier_dimanche_d_octobre(temps_utc, 3);
	date_tm = localtime(&date_time_t);
        printf("Date du dernier dimanche d'octobre (heure d'été -> heure d'hiver pour l'Europe): %d / %d / %d.\n", date_tm->tm_mday, (date_tm->tm_mon + 1), date_tm->tm_year + 1900);

	date_time_t = date_du_deuxieme_dimanche_de_mars(temps_utc);
	date_tm = localtime(&date_time_t);
        printf("Date du deuxieme dimanche de mars (heure d'hiver -> heure d'été pour l'Amérique du Nord): %d / %d / %d.\n", date_tm->tm_mday, (date_tm->tm_mon + 1), date_tm->tm_year + 1900);

	date_time_t = date_du_premier_dimanche_de_novembre(temps_utc);
	date_tm = localtime(&date_time_t);
        printf("Date du premier dimanche de novembre (heure d'été -> heure d'hiver pour l'Amerique du Nord): %d / %d / %d.\n", date_tm->tm_mday, (date_tm->tm_mon + 1), date_tm->tm_year + 1900);

	date_time_t = date_du_premier_dimanche_d_avril(temps_utc, 2);
	date_tm = localtime(&date_time_t);
        printf("Date du premier dimanche d'Avril (heure d'été -> heure d'hiver pour l'Australie): %d / %d / %d.\n", date_tm->tm_mday, (date_tm->tm_mon + 1), date_tm->tm_year + 1900);

	date_time_t = date_du_premier_dimanche_d_octobre(temps_utc);
	date_tm = localtime(&date_time_t);
        printf("Date du premier dimanche d'Octobre (heure d'hiver -> heure d'été pour l'Australie): %d / %d / %d.\n", date_tm->tm_mday, (date_tm->tm_mon + 1), date_tm->tm_year + 1900);

	date_time_t = date_du_premier_dimanche_d_avril(temps_utc, 3);
        date_tm = localtime(&date_time_t);
        printf("Date du premier dimanche d'Avril (heure d'été -> heure d'hiver pour la Nouvelle-Zélande): %d / %d / %d.\n", date_tm->tm_mday, (date_tm->tm_mon + 1), date_tm->tm_year + 1900);

        date_time_t = date_du_dernier_dimanche_de_septembre(temps_utc);
        date_tm = localtime(&date_time_t);
        printf("Date du dernier dimanche de Septembre (heure d'hiver -> heure d'été pour la Nouvelle-Zélande): %d / %d / %d.\n", date_tm->tm_mday, (date_tm->tm_mon + 1), date_tm->tm_year + 1900);

	date_time_t = date_du_deuxieme_dimanche_de_mai(temps_utc);
	date_tm = localtime(&date_time_t);
        printf("Date du deuxieme dimanche de Mai (heure d'été -> heure d'hiver pour le Chili): %d / %d / %d.\n", date_tm->tm_mday, (date_tm->tm_mon + 1), date_tm->tm_year + 1900);

	date_time_t = date_du_deuxieme_dimanche_d_aout(temps_utc);
	date_tm = localtime(&date_time_t);
        printf("Date du deuxieme dimanche d'Aout (heure d'hiver -> heure d'été pour le Chili): %d / %d / %d.\n", date_tm->tm_mday, (date_tm->tm_mon + 1), date_tm->tm_year + 1900);

	//Saut de ligne (pour la lisibilité)
	printf("\n\n");

  	//Tout va bien (donc EXIT_SUCCESS)
  	return 0;
}
```

<a name="liens_utiles"></a>
## Liens utiles

<a name="conclusion"></a>
## Conclusion
