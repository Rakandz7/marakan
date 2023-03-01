#include "consigne.h"

/***
 * @function Cette fonction correspond à la lecture de la consigne de l'utilisateur pour la température souhaitée via le fichier consigne.txt
 * @param thermostatPrec_f float | ce paramètre correspond à l'ancienne consigne de l'utilisateur
 * @return float | retourne la consigne de l'utilisateur en degrés
 */
float consigne(float thermostatPrec_f){
   float thermostat_f=0;
   // Verification de l'existance du fichier .verrouConsigne
   if(access(".verrouConsigne", F_OK) != -1){
       // Fichier existe
       return thermostatPrec_f; // retourne la consigne précédente
   }
   else{
       // Fichier n'exsite pas
       FILE* verrouConsigne = NULL;
       verrouConsigne = fopen(".verrouConsigne", "w");
       if (verrouConsigne == NULL){
           printf("Le fichier .verrouConsigne n'as pas pu être créer");
       }
       FILE* consigne = NULL;
       consigne = fopen("consigne.txt", "r");
       if (consigne != NULL){
           fscanf(consigne, "%f\n", &thermostat_f);
           fclose(consigne);
       }
       else{
           printf("Impossible d'ouvrir consigne.txt");
       }
       remove(".verrouConsigne");
   }
   return thermostat_f; // retourne la nouvelle consigne
}