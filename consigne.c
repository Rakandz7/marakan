#include "consigne.h"


/***
 * @brief cette fonction correspond à la lecture de la consigne de l'utilisateur pour la température souhaitée via le fichier consigne.txt
 * @param thermostatPrec_f float | ce paramètre correspond à l'ancienne consigne de l'utilisateur
 * @return float | retourne la consigne de l'utilisateur en degrés
 */
float consigne(float thermostatPrec_f){
   float thermostat_f = 0.0; // consigne du chauffage en °C
   // verification de l'existance du fichier .verrouConsigne
   if(access(".verrouConsigne", F_OK) != -1){
       // fichier .verrouConsigne existe
       return thermostatPrec_f; // retourne la consigne précédente
   }
   else{
       // fichier .verrouConsigne n'exsite pas
       FILE* verrouConsigne = NULL; // initialisation de verrouConsigne à NULL
       verrouConsigne = fopen(".verrouConsigne", "w"); // création du fichier .verrouConsigne
       // vérification de la création du fichier .verrouConsigne
       if (verrouConsigne == NULL){
           // fichier .verrouConsigne ne s'est pas créer
           fprintf(stderr, "le fichier .verrouConsigne n'a pas pu s'ouvrir\n"); // affichage dans le terminale de l'erreur
           exit(0);
       }
       else{
           // fichier .verrouConsigne s'est créer
           FILE* consigne = NULL; // initialisation de consigne à NULL
           consigne = fopen("consigne.txt", "r"); // ouverture du fichier consigne.txt en lecture
           // vérification de l'ouverture du fichier consigne.txt
           if (consigne != NULL){
               // fichier consigne.txt s'est ouvert
               fscanf(consigne, "%f\n", &thermostat_f); // lecture de la consigne en °C
               fclose(consigne); // fermeture du fichier consigne.txt
           }
           else{
               // fichier consigne.txt ne s'est pas ouvert
               fprintf(stderr, "Le fichier consigne.txt ne s'est pas ouvert\n"); // affichage dans le terminale de l'erreur
               exit(0);
           }
           fclose(verrouConsigne); // fermeture du fichier .verrouConsigne
           int error = remove(".verrouConsigne"); // suppression du fichier .verrouConsigne
           // vérification de la fermeture de .verrouConsigne
           if (error != 0){
               // fichier .verrouConsigne ne s'est pas supprimé
               printf("unable to remove .verrouConsigne\n"); // affichage dans le terminale de l'erreur
           }
       }
   }
   return thermostat_f; // retourne la nouvelle consigne en °C
}