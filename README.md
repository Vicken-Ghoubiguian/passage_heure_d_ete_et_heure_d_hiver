# passage_heure_d_ete_et_heure_d_hiver

Bibliothèque de fonctions de calcul des dates de passage à l'heure d'été et à l'heure d'hiver, et du décalage horaire actuel avec la France, pour plusieurs pays et régions du monde à partir de l'heure et de la date courantes de la timezone __Europe/Paris__.

## Sommaire

<a name="comment_compiler_cette_bibliotheque"></a>
## Comment compiler cette bibliothèque ?

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
