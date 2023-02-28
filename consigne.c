#include "consigne.h"

    float consigne(float thermostatPrec_f){
   
       float thermostat_f=0;

       // Verification de l'existance du fichier .verrouConsigne
       if(access(".verrouConsigne", F_OK) != -1){
           // Fichier existe
           return thermostatPrec_f;
       }
       else{
           // Fichier n'exsite pas
           FILE* verrouData = NULL;
           verrouData = fopen(".verrouConsigne", "w");
           if (verrouData == NULL){
               printf("Le fichier .verrouConisgne n'as pas pu être créer");
           }
           FILE* consigne = NULL;
           consigne = fopen("consigne.txt", "r");
           if (consigne != NULL){
               fscanf(consigne, "%f", &thermostat_f); // on lit la première ligne
               fclose(consigne);
           }
           else{
               printf("Impossible d'ouvrir consigne.txt");
           }
           remove(".verrouConsigne");
       }
    return thermostat_f;
    }