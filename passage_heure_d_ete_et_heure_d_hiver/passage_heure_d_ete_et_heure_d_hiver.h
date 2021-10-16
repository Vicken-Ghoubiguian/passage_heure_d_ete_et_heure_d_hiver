#ifndef PASSAGE_HEURE_D_ETE_ET_HEURE_D_HIVER
#define PASSAGE_HEURE_D_ETE_ET_HEURE_D_HIVER

#include <time.h>

// Cette fonction calcule puis retourne le temps UTC sous forme d'un timestamp

// Cette fonction calcule puis retourne le temps UTC sous forme d'un struct tm

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'été (pour les pays européens) à l'aide du timestamp et de l'heure (1 pour la Grande Bretagne et 2 pour la France) passé en paramétre
time_t date_du_dernier_dimanche_de_mars(time_t aujourdhui, int heure);

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'hiver (pour les pays européens) à l'aide du timestamp et de l'heure (2 pour la Grande Bretagne et 3 pour la France) passé en paramétre
time_t date_du_dernier_dimanche_d_octobre(time_t aujourdhui, int heure);

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'hiver (pour l'Australie et la Nouvelle-Zélande) à l'aide du timestamp et de l'heure (2 pour l'Australie, 3 pour la Nouvelle-Zélande) passés en paramétres
time_t date_du_premier_dimanche_d_avril(time_t aujourdhui, int heure);

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'été (pour l'Australie) à l'aide du timestamp passé en paramétre
time_t date_du_premier_dimanche_d_octobre(time_t aujourdhui);

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'hiver pour l'Amerique du Nord à l'aide du timestamp
time_t date_du_premier_dimanche_de_novembre(time_t aujourdhui);

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'été pour l'Amerique du Nord à l'aide du timestamp passé en paramétre
time_t date_du_deuxieme_dimanche_de_mars(time_t aujourdhui);

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'hiver (pour le Chili) à l'aide du timestamp passé en paramétre
time_t date_du_deuxieme_dimanche_de_mai(time_t aujourdhui);

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'été (pour le Chili) à l'aide du timestamp passé en paramétre
time_t date_du_deuxieme_dimanche_d_aout(time_t aujourdhui);

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'été (pour la Nouvelle-Zelande) à l'aide du timestamp passé en paramétre
time_t date_du_dernier_dimanche_de_septembre(time_t aujourdhui);

//Cette fonction permet de déterminer si il faut (ou non) en fonction du changement d'heure ajouter une heure (ou non) pour le calcul des fuseaux horaires de Pekin, Tokyo, Seoul, Moscou, et Vladivostok
int application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(time_t date);

//Cette fonction permet de calculer le decallage horaire de Wellington (Nouvelle-Zelande) avec l'heure française
int calcul_du_decalage_avec_wellington(time_t aujourdhui);

//Cette fonction permet de calculer le decallage horaire de Canberra (Australie) avec l'heure française
int calcul_du_decalage_avec_canberra(time_t aujourdhui);

//Cette fonction permet de calculer le decallage horaire de Santiago du Chili (Chili) avec l'heure française
int calcul_du_decalage_avec_le_chili(time_t aujourdhui);

//Cette fonction permet de calculer le decallage horaire de Los Angeles et de New York City (USA) avec l'heure française
int calcul_du_decalage_avec_l_amerique_du_nord(time_t aujourdhui);

//Cette fonction permet de calculer le decallage horaire de Londres avec l'heure française
int calcul_du_decallage_avec_la_grande_bretagne(time_t aujourdhui);

//Cette fonction permet de calculer et d'afficher les horaires d'une ville passée en paramétre
void calcul_et_affichage_horaire(time_t temps, char* ville);

//Fonction d'affichage de l'horloge
void affichage_de_l_horloge(time_t temps_courant);

//Cette fonction permet de calculer et de renvoyer les horaires pour une ville spécifiée en paramétre
char* calcul_et_renvoie_horaire(time_t temps, char* ville);

//Cette fonction calcule puis retourne l'heure et la date pour une ville déterminée et connue passée en paramétre sous forme d'une chaine de caractères
char* retour_de_l_heure_et_de_la_date_pour_une_ville_determinee_et_connue(time_t temps_courant, char* nom_de_la_ville);

#endif
