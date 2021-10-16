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

	//Saut de ligne (pour la lisibilité)
	printf("\n\n");

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

	//Tests effectués sur les décallages horaires
	printf("Voici le décallage de Canberra: +%d.\n", 10 - calcul_du_decalage_avec_canberra(la));
	printf("Voici le décallage de Santiago du Chili: -%d.\n", 6 - calcul_du_decalage_avec_le_chili(la));
	printf("Voici le decallage de Johannesburg: +%d.\n", 0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(la));
	printf("Voici le decallage de Buenos Aires: -%d.\n", 5 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(la));
	printf("Voici le decallage de Antananarivo: +%d.\n", 1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(la));
	printf("Voici le decallage de Windhoek: +%d.\n", 0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(la));
	printf("Voici le decallage de Lima: -%d.\n", 7 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(la));
	printf("Voici le decallage de Wellington: +%d.\n", 12 -  calcul_du_decalage_avec_wellington(la));
	printf("Voici le décalage de Los Angeles : -%d.\n", 9 - calcul_du_decalage_avec_l_amerique_du_nord(la));
	printf("Voici le décalage de New York City : -%d.\n", 6 - calcul_du_decalage_avec_l_amerique_du_nord(la));
	printf("Voici le décalage de Phoenix: -%d.\n", 9 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(la));
	printf("Voici le décalage de Londres: -%d.\n", 1 - calcul_du_decallage_avec_la_grande_bretagne(la));
	printf("Voici le decalage de Ottawa: -%d.\n", 6 - calcul_du_decalage_avec_l_amerique_du_nord(la));
	printf("Voici le décalage de Moscou : +%d.\n", 1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(la));
	printf("Voici le décalage de Vladivostok : +%d.\n", 8 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(la));
	printf("Voici le décalage de Seoul : +%d.\n", 7 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(la));
	printf("Voici le décalage de Tokyo: +%d.\n", 7 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(la));
	printf("Voici le décalage de Pekin : +%d.\n", 6 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(la));

	//Appel à la fonction affichage_de_l_horloge avec comme paramétre le temps courant sous forme d'un timestamp (time_t)
	affichage_de_l_horloge(la);

	// Calcul et retour du temps (la date et l'heure) courant à Séoul sous forme d'une chaine de caractères 
    char* date_et_heure_a_seoul = retour_de_l_heure_et_de_la_date_pour_une_ville_determinee_et_connue(la, "Seoul");

    // Affichage du temps (la date et l'heure) courant à Seoul
    printf("%s\n", date_et_heure_a_seoul);

	//Saut de ligne (pour la lisibilité)
	printf("\n\n");

	//Tout va bien (donc EXIT_SUCCESS)
	return 0;
}
