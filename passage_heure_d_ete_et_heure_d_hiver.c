#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "passage_heure_d_ete_et_heure_d_hiver.h"

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'été (pour les pays européens) à l'aide du timestamp et de l'heure (1 pour la Grande Bretagne et 2 pour la France) passé en paramétre
time_t date_du_dernier_dimanche_de_mars(time_t aujourdhui, int heure)
{
	//Déclaration des variables necessaires au calcul de l'horaire de changement d'heure d'été
	struct tm *date_tm;
	time_t date_timestamp;

	//la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
	date_tm = localtime(&aujourdhui);

	//la structure date_tm est modifiée pour correspondre au 1er (tm_mday) avril (tm_mon) à 2 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
	date_tm->tm_mday = 1;
        date_tm->tm_mon = 3;
	date_tm->tm_hour = heure;
	date_tm->tm_min = 0;
	date_tm->tm_sec = 0;
	
	//la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction mktime
	//Puis reconvertie en struct tm grace à la fonction localtime
	date_timestamp = mktime(date_tm);
	date_tm = localtime(&date_timestamp);
	
	//Ici, le programme procéde à une boucle infinie
	while(1){
		
		//On affecte à la variable date_timestamp la différence entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
		date_timestamp = date_timestamp - 86400;

		//La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
		date_tm = localtime(&date_timestamp);

		//Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond au dernier dimanche (tm_wday) du mois de Mars (tm_mon), on quitte définitivement la boucle
		if(date_tm->tm_wday == 0 && date_tm->tm_mon == 2)
		{
			break;
		}
	}

	//On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
	return date_timestamp;
}

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'hiver (pour les pays européens) à l'aide du timestamp et de l'heure (2 pour la Grande Bretagne et 3 pour la France) passé en paramétre
time_t date_du_dernier_dimanche_d_octobre(time_t aujourdhui, int heure)
{
	//Déclaration des variables necessaires au calcul de l'horaire de changement d'heure d'été
        struct tm *date_tm;
        time_t date_timestamp;

	//la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
	date_tm = localtime(&aujourdhui);

	//la structure date_tm est modifiée pour correspondre au 1er (tm_mday) novembre (tm_mon) à 3 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = 10;
	date_tm->tm_hour = heure;
        date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

	//la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction mktime
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = mktime(date_tm);
        date_tm = localtime(&date_timestamp);

	//Ici, le programme procéde à une boucle infinie
        while(1){
		
		//On affecte à la variable date_timestamp la différence entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                date_timestamp = date_timestamp - 86400;

		//La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
                date_tm = localtime(&date_timestamp);
                
		//Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond au dernier dimanche (tm_wday) du mois d'Octobre (tm_mon), on quitte définitivement la boucle
		if(date_tm->tm_wday == 0 && date_tm->tm_mon == 9)
		{
			break;
		}
        }

	//On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
	return date_timestamp;
}



//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'hiver (pour l'Australie et la Nouvelle-Zélande) à l'aide du timestamp et de l'heure (2 pour l'Australie, 3 pour la Nouvelle-Zélande) passés en paramétres
time_t date_du_premier_dimanche_d_avril(time_t aujourdhui, int heure)
{
        //Déclaration des variables necessaires au calcul de l'horaire de changement d'heure d'hiver
        struct tm *date_tm;
        time_t date_timestamp;

        //la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
        date_tm = localtime(&aujourdhui);

        //la structure date_tm est modifiée pour correspondre au 1er (tm_mday) avril (tm_mon) de l'annee prochaine (tm_year) à heure (passé en paramétre) heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = 3;
        date_tm->tm_hour = heure;
        date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

	//la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction mktime
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = mktime(date_tm);
        date_tm = localtime(&date_timestamp);

        //Définition d'une variable i qui va contenir le nombre de dimanche comptabilisé dans notre parcours du mois de novembre
        int i;

        //Si le jour de la semaine (renseignée par le champ tm_wday) est dimanche (valeur = 0), alors, la variable i est initialisée à la valeur 1
        if(date_tm->tm_wday == 0)
        {
                i = 1;
        }
        //Dans le cas contraire, la variable i est initialisée à la valeur 0
        else
        {
                i = 0;
        }

        //la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction mktime
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = mktime(date_tm);
        date_tm = localtime(&date_timestamp);

        //Ici, le programme procéde à une boucle infinie
        while(1){

                //Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond au dernier dimanche (tm_wday) du mois d'Octobre (tm_mon), et que i est égal à 1, on quitte définitivement la boucle
                if(date_tm->tm_wday == 0 && date_tm->tm_mon == 3 && i == 1)
                {
                        break;

		}
		else
		{
			//On affecte à la variable date_timestamp la somme entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                	date_timestamp = date_timestamp + 86400;
			
                	//La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
                	date_tm = localtime(&date_timestamp);

			//Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond au premier dimanche (tm_wday) du mois d'Avril (tm_mon), la valeur contenue dans la variable i est augmentée de 1
                        if(date_tm->tm_wday == 0 && date_tm->tm_mon == 3)
                        {
                                i = i + 1;
                        }

                }
        }

        //On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
        return date_timestamp;
}

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'été (pour l'Australie) à l'aide du timestamp passé en paramétre
time_t date_du_premier_dimanche_d_octobre(time_t aujourdhui)
{
        //Déclaration des variables necessaires au calcul de l'horaire de changement d'heure d'été
        struct tm *date_tm;
        time_t date_timestamp;

        //la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
        date_tm = localtime(&aujourdhui);

        //la structure date_tm est modifiée pour correspondre au 1er (tm_mday) octobre (tm_mon) à 2 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = 9;
        date_tm->tm_hour = 2;
        date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

	//la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction mktime
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = mktime(date_tm);
        date_tm = localtime(&date_timestamp);

        //Définition d'une variable i qui va contenir le nombre de dimanche comptabilisé dans notre parcours du mois d'octobre 
        int i;

        //Si le jour de la semaine (renseignée par le champ tm_wday) est dimanche (valeur = 0), alors, la variable i est initialisée à la valeur 1
        if(date_tm->tm_wday == 0)
        {
                i = 1;
        }
        //Dans le cas contraire, la variable i est initialisée à la valeur 0
        else
        {
                i = 0;
        }

        //la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction mktime
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = mktime(date_tm);
        date_tm = localtime(&date_timestamp);

        //Ici, le programme procéde à une boucle infinie
        while(1){

                //Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond au dernier dimanche (tm_wday) du mois d'Octobre (tm_mon), et que i est égal à 1, on quitte définitivement la boucle
                if(date_tm->tm_wday == 0 && date_tm->tm_mon == 9 && i == 1)
                {
                        break;

		}
		//Dans le cas contraire
		else
		{
			//On affecte à la variable date_timestamp la somme entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                	date_timestamp = date_timestamp + 86400;

                	//La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
                	date_tm = localtime(&date_timestamp);

			//Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond au premier dimanche (tm_wday) du mois d'Octobre (tm_mon), la valeur contenue dans la variable i est augmentée de 1
                        if(date_tm->tm_wday == 0 && date_tm->tm_mon == 9)
                        {
                                i = i + 1;
                        }

                }
        }

        //On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
        return date_timestamp;
}

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'hiver pour l'Amerique du Nord à l'aide du timestamp
time_t date_du_premier_dimanche_de_novembre(time_t aujourdhui)
{
        //Déclaration des variables necessaires au calcul de l'horaire de changement d'heure d'été
        struct tm *date_tm;
        time_t date_timestamp;

        //la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
        date_tm = localtime(&aujourdhui);

        //la structure date_tm est modifiée pour correspondre au 1er (tm_mday) novembre (tm_mon) à 2 heures (USA) ou 0 (Bresil) (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = 10;
	date_tm->tm_hour = 2;
	date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

	//la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction mktime
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = mktime(date_tm);
        date_tm = localtime(&date_timestamp);

        //Définition d'une variable i qui va contenir le nombre de dimanche comptabilisé dans notre parcours du mois de novembre
        int i;

        //Si le jour de la semaine (renseignée par le champ tm_wday) est dimanche (valeur = 0), alors, la variable i est initialisée à la valeur 1
        if(date_tm->tm_wday == 0)
        {
                i = 1;
        }
        //Dans le cas contraire, la variable i est initialisée à la valeur 0
        else
        {
                i = 0;
        }

        //la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction mktime
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = mktime(date_tm);
        date_tm = localtime(&date_timestamp);

        //Ici, le programme procéde à une boucle infinie
        while(1){

                //Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond au dernier dimanche (tm_wday) du mois d'Octobre (tm_mon), et que i est égal à 1, on quitte définitivement la boucle
                if(date_tm->tm_wday == 0 && date_tm->tm_mon == 10 && i == 1)
                {
                        break;

		}
		//Dans le cas contraire
		else
		{
			//On affecte à la variable date_timestamp la somme entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                	date_timestamp = date_timestamp + 86400;

                	//La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
                	date_tm = localtime(&date_timestamp);

			//Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond au premier dimanche (tm_wday) du mois de Novembre (tm_mon), la valeur contenue dans la variable i est augmentée de 1
                        if(date_tm->tm_wday == 0 && date_tm->tm_mon == 10)
                        {
                                i = i + 1;
                        }

                }
        }

        //On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
        return date_timestamp;
}

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'été pour l'Amerique du Nord à l'aide du timestamp passé en paramétre
time_t date_du_deuxieme_dimanche_de_mars(time_t aujourdhui)
{
        //Déclaration des variables necessaires au calcul de l'horaire de changement d'heure d'été
        struct tm *date_tm;
        time_t date_timestamp;

        //la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
        date_tm = localtime(&aujourdhui);

        //la structure date_tm est modifiée pour correspondre au 1er (tm_mday) avril (tm_mon) à 2 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = 2;
        date_tm->tm_hour = 2;
        date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

	//la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction mktime
        //Puis reconvertie en struct tm grace à la fonction localtime
	date_timestamp = mktime(date_tm);
        date_tm = localtime(&date_timestamp);

	//Définition d'une variable i qui va contenir le nombre de dimanche comptabilisé dans notre parcours du mois de mars
	int i;

	//Si le jour de la semaine (renseignée par le champ tm_wday) est dimanche (valeur = 0), alors, la variable i est initialisée à la valeur 1
	if(date_tm->tm_wday == 0)
	{
		i = 1;
	}
	//Dans le cas contraire, la variable i est initialisée à la valeur 0
	else
	{
		i = 0;
	}

        //la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction mktime
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = mktime(date_tm);
        date_tm = localtime(&date_timestamp);

        //Ici, le programme procéde à une boucle infinie
        while(1){

                //On affecte à la variable date_timestamp la différence entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                date_timestamp = date_timestamp + 86400;

                //La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion en struct tm grace à la fonction localtime
                date_tm = localtime(&date_timestamp);

                //Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond au dernier dimanche (tm_wday) du mois de Mars (tm_mon) et que i = 1 (un dimanche du mois de mars est passé, et là on en est au second), on quitte définitivement la boucle
                if(date_tm->tm_wday == 0 && date_tm->tm_mon == 2 && i == 1)
                {
                        break;
                }
		//Dans le cas contraire
		else
		{
			//Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond au dernier dimanche (tm_wday) du mois de Mars (tm_mon), la valeur contenue dans la variable i est incrementé de 1
			if(date_tm->tm_wday == 0 && date_tm->tm_mon == 2)
			{
				i = i + 1;
			}
		}
        }

        //On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
        return date_timestamp;
}

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'hiver (pour le Chili) à l'aide du timestamp passé en paramétre
time_t date_du_deuxieme_dimanche_de_mai(time_t aujourdhui)
{
        //Déclaration des variables necessaires au calcul de l'horaire de changement d'heure d'été
        struct tm *date_tm;
        time_t date_timestamp;

        //la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
        date_tm = localtime(&aujourdhui);

        //la structure date_tm est modifiée pour correspondre au 1er (tm_mday) mai (tm_mon) à 2 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = 4;
        date_tm->tm_hour = 2;
        date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

	//la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction mktime
        //Puis reconvertie en struct tm grace à la fonction localtime
	date_timestamp = mktime(date_tm);
        date_tm = localtime(&date_timestamp);

	//Définition d'une variable i qui va contenir le nombre de dimanche comptabilisé dans notre parcours du mois de mars 
	int i;

	//Si le jour de la semaine (renseignée par le champ tm_wday) est dimanche (valeur = 0), alors, la variable i est initialisée à la valeur 1
	if(date_tm->tm_wday == 0)
	{
		i = 1;
	}
	//Dans le cas contraire, la variable i est initialisée à la valeur 0
	else
	{
		i = 0;
	}

        //la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction mktime
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = mktime(date_tm);
        date_tm = localtime(&date_timestamp);

        //Ici, le programme procéde à une boucle infinie
        while(1){

                //On affecte à la variable date_timestamp la différence entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                date_timestamp = date_timestamp + 86400;

                //La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
                date_tm = localtime(&date_timestamp);

                //Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond au deuxieme dimanche (tm_wday) du mois de Mai (tm_mon) et que i = 1 (un dimanche du mois de Mai est passé, là on en est au deuxieme), on quitte définitivement la boucle
                if(date_tm->tm_wday == 0 && date_tm->tm_mon == 4 && i == 1)
                {
                        break;
                }
		//Dans le cas contraire
		else
		{
			//Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond au deuxieme dimanche (tm_wday) du mois de Mai (tm_mon), la valeur contenue dans la variable i est incrementé de 1
			if(date_tm->tm_wday == 0 && date_tm->tm_mon == 4)
			{
				i = i + 1;
			}
		}
        }

        //On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
        return date_timestamp;
}

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'été (pour le Chili) à l'aide du timestamp passé en paramétre
time_t date_du_deuxieme_dimanche_d_aout(time_t aujourdhui)
{
        //Déclaration des variables necessaires au calcul de l'horaire de changement d'heure d'été
        struct tm *date_tm;
        time_t date_timestamp;

        //la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
        date_tm = localtime(&aujourdhui);

        //la structure date_tm est modifiée pour correspondre au 1er (tm_mday) Aout (tm_mon) à 2 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = 7;
        date_tm->tm_hour = 2;
        date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

	//la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction mktime
        //Puis reconvertie en struct tm grace à la fonction localtime
	date_timestamp = mktime(date_tm);
        date_tm = localtime(&date_timestamp);

	//Définition d'une variable i qui va contenir le nombre de dimanche comptabilisé dans notre parcours du mois d'Aout
	int i;

	//Si le jour de la semaine (renseignée par le champ tm_wday) est dimanche (valeur = 0), alors, la variable i est initialisée à la valeur 1
	if(date_tm->tm_wday == 0)
	{
		i = 1;
	}
	//Dans le cas contraire, la variable i est initialisée à la valeur 0
	else
	{
		i = 0;
	}

        //la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction mktime
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = mktime(date_tm);
        date_tm = localtime(&date_timestamp);

        //Ici, le programme procéde à une boucle infinie
        while(1){

                //On affecte à la variable date_timestamp la différence entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                date_timestamp = date_timestamp + 86400;

                //La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
                date_tm = localtime(&date_timestamp);

                //Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond au deuxieme dimanche (tm_wday) du mois d'Aout (tm_mon) et que i = 1 (un dimanche du mois d'Aout est passé, là on en est au second), on quitte définitivement la boucle
                if(date_tm->tm_wday == 0 && date_tm->tm_mon == 7 && i == 1)
                {
                        break;
                }
		//Dans le cas contraire
		else
		{
			//Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond au deuxieme dimanche (tm_wday) du mois de Aout (tm_mon), la valeur contenue dans la variable i est incrementé de 1
			if(date_tm->tm_wday == 0 && date_tm->tm_mon == 7)
			{
				i = i + 1;
			}
		}
        }

        //On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
        return date_timestamp;
}

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'été (pour la Nouvelle-Zelande) à l'aide du timestamp passé en paramétre
time_t date_du_dernier_dimanche_de_septembre(time_t aujourdhui)
{
        //Déclaration des variables necessaires au calcul de l'horaire de changement d'heure d'été
        struct tm *date_tm;
        time_t date_timestamp;

        //la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
        date_tm = localtime(&aujourdhui);

        //la structure date_tm est modifiée pour correspondre au 1er (tm_mday) octobre (tm_mon) à 2 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = 9;
        date_tm->tm_hour = 2;
        date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

        //la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction mktime
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = mktime(date_tm);
        date_tm = localtime(&date_timestamp);

        //Ici, le programme procéde à une boucle infinie
        while(1){

                //On affecte à la variable date_timestamp la différence entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                date_timestamp = date_timestamp - 86400;

                //La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
                date_tm = localtime(&date_timestamp);

                //Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond au dernier dimanche (tm_wday) du mois de Septembre (tm_mon), on quitte définitivement la boucle
                if(date_tm->tm_wday == 0 && date_tm->tm_mon == 8)
                {
                        break;
                }
        }

        //On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
        return date_timestamp;
}

//Cette fonction permet de déterminer si il faut (ou non) en fonction du changement d'heure ajouter une heure (ou non) pour le calcul des fuseaux horaires de Pekin, Tokyo, Seoul, Moscou, et Vladivostok
int application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(time_t date)
{
	//On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour prrocéder aux calculs
	time_t ete = date_du_dernier_dimanche_de_mars(date, 2);
	time_t hiver = date_du_dernier_dimanche_d_octobre(date, 3);

	//Ici, on vérifie (grace à des comparaison de valeurs entre timestamp) que la date se situe entre ete et hiver (inclus)
	//Si la date passée en paramétre se situe entre l'horaire de changement de l'heure d'été et celui de changement de l'heure d'hiver, 0 est retourné (il y à aucune heure à ajouter)
	if(date >= ete && date <= hiver)
	{
		return 0;
	}
	//Sinon, 1 est retourné (il faudra ajouter une heure)
	else
	{
		return 1;
	}
}

//Cette fonction permet de calculer le decallage horaire de Wellington (Nouvelle-Zelande) avec l'heure française
int calcul_du_decalage_avec_wellington(time_t aujourdhui)
{
	//Définition des variables nécessaires au calcul du décalage
        time_t date_passage_heure_d_ete_europe = date_du_dernier_dimanche_de_mars(aujourdhui, 2);
        time_t date_passage_heure_d_hiver_europe = date_du_dernier_dimanche_d_octobre(aujourdhui, 3);
        time_t date_passage_heure_d_ete_nouvelle_zelande = date_du_dernier_dimanche_de_septembre(aujourdhui);
        time_t date_passage_heure_d_hiver_nouvelle_zelande = date_du_premier_dimanche_d_avril(aujourdhui, 3);

	//Calcul du décallage en fonction de l'interval de temps dans lequel est la valeur passée en paramétre
	if((aujourdhui >= date_passage_heure_d_ete_europe && aujourdhui < date_passage_heure_d_hiver_nouvelle_zelande) || (aujourdhui >= date_passage_heure_d_ete_nouvelle_zelande && aujourdhui < date_passage_heure_d_hiver_europe))
	{
		return 1;
	}
	else if(aujourdhui >= date_passage_heure_d_hiver_nouvelle_zelande && aujourdhui < date_passage_heure_d_ete_nouvelle_zelande)
	{
		return 2;
	}
	else
	{
		return 0;
	}
}

//Cette fonction permet de calculer le decallage horaire de Canberra (Australie) avec l'heure française
int calcul_du_decalage_avec_canberra(time_t aujourdhui)
{
	//Définition des variables nécessaires au calcul du décalage
	time_t date_passage_heure_d_ete_europe = date_du_dernier_dimanche_de_mars(aujourdhui, 2);
	time_t date_passage_heure_d_hiver_europe = date_du_dernier_dimanche_d_octobre(aujourdhui, 3);
	time_t date_passage_heure_d_ete_australie = date_du_premier_dimanche_d_octobre(aujourdhui);
	time_t date_passage_heure_d_hiver_australie = date_du_premier_dimanche_d_avril(aujourdhui, 2);

	//Calcul du décalage en fonction de l'interval de temps dans lequel est la valeur passée en paramétre
	if((aujourdhui >= date_passage_heure_d_ete_europe && aujourdhui < date_passage_heure_d_hiver_australie) || (aujourdhui >= date_passage_heure_d_ete_australie && aujourdhui < date_passage_heure_d_hiver_europe))
	{
		return 1;
	}
	else if(aujourdhui >= date_passage_heure_d_hiver_australie && aujourdhui < date_passage_heure_d_ete_australie)
	{
		return 2;
	}
	else
	{
		return 0;
	}
}

//Cette fonction permet de calculer le decallage horaire de Santiago du Chili (Chili) avec l'heure française
int calcul_du_decalage_avec_le_chili(time_t aujourdhui)
{
	//Définition des variables nécessaires au calcul du décalage
	time_t date_passage_heure_d_ete_europe = date_du_dernier_dimanche_de_mars(aujourdhui, 2);
	time_t date_passage_heure_d_hiver_europe = date_du_dernier_dimanche_d_octobre(aujourdhui, 3);
	time_t date_passage_heure_d_ete_chili = date_du_deuxieme_dimanche_d_aout(aujourdhui);
	time_t date_passage_heure_d_hiver_chili = date_du_deuxieme_dimanche_de_mai(aujourdhui);

	//Calcul du décalage en fonction de l'interval de temps dans lequel est la valeur passée en paramétre
	if((aujourdhui >= date_passage_heure_d_ete_europe && aujourdhui < date_passage_heure_d_hiver_chili) || (aujourdhui >= date_passage_heure_d_ete_chili && aujourdhui < date_passage_heure_d_hiver_europe))
	{
		return 1;
	}
	else if(aujourdhui >= date_passage_heure_d_hiver_chili && aujourdhui < date_passage_heure_d_ete_chili && aujourdhui > date_passage_heure_d_ete_europe)
	{
		return 0;
	}
	else
	{
		return 2;
	}
}

//Cette fonction permet de calculer le decallage horaire de Los Angeles et de New York City (USA) avec l'heure française
int calcul_du_decalage_avec_l_amerique_du_nord(time_t aujourdhui)
{
	//Définition des variables nécessaires au calcul du décalage
	time_t date_passage_heure_d_ete_europe = date_du_dernier_dimanche_de_mars(aujourdhui, 2);
	time_t date_passage_heure_d_hiver_europe = date_du_dernier_dimanche_d_octobre(aujourdhui, 3);
	time_t date_passage_heure_d_ete_usa = date_du_deuxieme_dimanche_de_mars(aujourdhui);
	time_t date_passage_heure_d_hiver_usa = date_du_premier_dimanche_de_novembre(aujourdhui);

	//Calcul du décalage en fonction de l'interval de temps dans lequel est la valeur passée en paramétre
	if((aujourdhui >= date_passage_heure_d_ete_usa && aujourdhui < date_passage_heure_d_ete_europe) || (aujourdhui >= date_passage_heure_d_hiver_europe && aujourdhui < date_passage_heure_d_hiver_usa))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//Cette fonction permet de calculer le decallage horaire de Londres avec l'heure française
int calcul_du_decallage_avec_la_grande_bretagne(time_t aujourdhui)
{
	//Définition des variables nécessaires au calcul du décalage
        time_t date_passage_heure_d_ete_france = date_du_dernier_dimanche_de_mars(aujourdhui, 2);
        time_t date_passage_heure_d_hiver_france = date_du_dernier_dimanche_d_octobre(aujourdhui, 3);
	time_t date_passage_heure_d_ete_uk = date_du_dernier_dimanche_de_mars(aujourdhui, 1);
	time_t date_passage_heure_d_hiver_uk = date_du_dernier_dimanche_d_octobre(aujourdhui, 2);

	//Calcul du décalage en fonction de l'interval de temps dans lequel est la valeur passée en paramétre
	if(((aujourdhui > date_passage_heure_d_ete_uk) && (aujourdhui < date_passage_heure_d_ete_france)) || ((aujourdhui > date_passage_heure_d_hiver_uk) && (aujourdhui < date_passage_heure_d_hiver_france)))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//Cette fonction permet de calculer et d'afficher les horaires
void calcul_et_affichage_horaire(time_t temps, char* ville)
{
	//Declaration des variables
	struct tm *horaire = localtime(&temps);
	char* jour_semaine;
	char* mois;

	//Definition du mois en court en fonction du champs tm_mon de la structure tm
	switch(horaire->tm_mon)
	{
		case 0: mois = "Janvier"; break;
		case 1: mois = "Fevrier"; break;
		case 2: mois = "Mars"; break;
		case 3: mois = "Avril"; break;
		case 4: mois = "Mai"; break;
		case 5: mois = "Juin"; break;
		case 6: mois = "Juillet"; break;
		case 7: mois = "Aout"; break;
		case 8: mois = "Septembre"; break;
		case 9: mois = "Octobre"; break;
		case 10: mois = "Novembre"; break;
		case 11: mois = "Decembre"; break;
	}	

	//Definition du jour de la semaine en fonction du champs tm_wday de la structure tm
	switch(horaire->tm_wday)
	{
		case 0: jour_semaine = "Dimanche"; break;
		case 1: jour_semaine = "Lundi"; break;
		case 2: jour_semaine = "Mardi"; break;
		case 3: jour_semaine = "Mercredi"; break;
		case 4: jour_semaine = "Jeudi"; break;
		case 5: jour_semaine = "Vendredi"; break;
		case 6: jour_semaine = "Samedi"; break;
	}

	//Affichage de l'horaire
	printf("%s : %d:%d:%d - %s %d %s %d.\n",
		ville, horaire->tm_hour, horaire->tm_min, horaire->tm_sec,
		jour_semaine, horaire->tm_mday, mois, horaire->tm_year + 1900);
}

//Fonction de test pour les calculs d'horaires mises au point dans le fichier heure_monde.c
void affichage_de_l_horloge(time_t temps_courant)
{

	/*Calcul des horaires de différents villes du monde et affectation de la valeur calculée à une variable correspondante*/
	time_t heure_los_angeles = temps_courant - ((9 - calcul_du_decalage_avec_l_amerique_du_nord(temps_courant)) * 3600); //Los Angeles
	time_t heure_de_nyc = temps_courant - ((6 - calcul_du_decalage_avec_l_amerique_du_nord(temps_courant)) * 3600); //New York City
	time_t heure_d_ottawa = temps_courant - ((6 - calcul_du_decalage_avec_l_amerique_du_nord(temps_courant)) * 3600);//Ottawa
	time_t heure_de_phoenix = temps_courant - ((9 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);//Phoenix
	time_t heure_de_londres = temps_courant - (1 * 3600); //Londres
	time_t heure_moscou = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Moscou
	time_t heure_vladivostok = temps_courant + ((8 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Vladivostok
	time_t heure_canberra = temps_courant + ((10 - calcul_du_decalage_avec_canberra(temps_courant)) * 3600); //Canberra
	time_t heure_santiago_chili = temps_courant - ((6 - calcul_du_decalage_avec_le_chili(temps_courant)) * 3600); //Santiago du Chili
	time_t heure_johannesburg = temps_courant + ((0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Johannesburg
	time_t heure_windhoek = temps_courant + ((0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Windhoek
	time_t heure_buenos_aires = temps_courant - ((5 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Buenos Aires
	time_t heure_antananarivo = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Antananarivo
	time_t heure_lima = temps_courant - ((7 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Lima
	time_t heure_wellington = temps_courant + ((12 -  calcul_du_decalage_avec_wellington(temps_courant)) * 3600); //Wellington
	time_t heure_seoul = temps_courant + ((7 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Seoul
	time_t heure_tokyo = temps_courant + ((7 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Tokyo
	time_t heure_pekin = temps_courant + ((6 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Pekin

	/*Affichage des différents horiares calculés à coté des villes correspondantes*/
	printf("\n");
	calcul_et_affichage_horaire(temps_courant, "Perpignan");
	calcul_et_affichage_horaire(heure_los_angeles, "Los Angeles");
	calcul_et_affichage_horaire(heure_de_nyc, "New York City");
	calcul_et_affichage_horaire(heure_d_ottawa, "Ottawa");
	calcul_et_affichage_horaire(heure_de_phoenix, "Phoenix");
	calcul_et_affichage_horaire(heure_de_londres, "Londres");
	calcul_et_affichage_horaire(heure_moscou, "Moscou");
	calcul_et_affichage_horaire(heure_vladivostok, "Vladivostok");
	calcul_et_affichage_horaire(heure_canberra, "Canberra");
	calcul_et_affichage_horaire(heure_santiago_chili, "Santiago du Chili");
	calcul_et_affichage_horaire(heure_johannesburg, "Johannesburg");
	calcul_et_affichage_horaire(heure_buenos_aires, "Buenos Aires");
	calcul_et_affichage_horaire(heure_antananarivo, "Antananarivo");
	calcul_et_affichage_horaire(heure_wellington, "Wellington");
	calcul_et_affichage_horaire(heure_windhoek, "Windhoek");
	calcul_et_affichage_horaire(heure_lima, "Lima");
	calcul_et_affichage_horaire(heure_seoul, "Seoul");
	calcul_et_affichage_horaire(heure_tokyo, "Tokyo");
	calcul_et_affichage_horaire(heure_pekin, "Pekin");
	printf("\n");
}
