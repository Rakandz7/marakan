#include "visualisationT.h"

void visualisationT(temp_t myTemp){
   // Verification de l'existance du fichier .verrouData
   if(access(".verrouData", F_OK) != -1){
        // Fichier existe
        return;
   }
   else{
        // Fichier n'exsite pas
        FILE* verrouData = NULL;
        verrouData = fopen(".verrouData", "w");
        if (verrouData == NULL){
            fprintf(stderr, "le fichier .verrouData n'a pas pu s'ouvrir\n");
            exit(0);
        }
        FILE* data = NULL;
        data = fopen("data.txt", "r");
        float tempExt; // température intérieur
        float tempInt; // température extérieur
        char ioChauff[10]; // Chaine vide pour la l'allumage du chauffage true ou false
        if (data != NULL){
            fscanf(data, "%f", &tempExt); // on lit la première ligne
            fscanf(data, "%f", &tempInt); // on lit la deuxième ligne
            fscanf(data, "%s", ioChauff); // on lit la trosième ligne
            fclose(data);
        }
        else{
            fprintf(stderr, "Le fichier data.txt ne s'est pas ouvert\n");
            exit(0);
        }
        data = fopen("data.txt", "w");
        if (data != NULL){
            fprintf(data, "%f\n", myTemp.exterieure); // on écrit la première ligne
            fprintf(data, "%f\n", myTemp.interieure); // on écrit la deuxième ligne
            fprintf(data, "%s\n", ioChauff); // on écrit la troisième ligne
            fclose(data);
        }
        remove(".verrouData");
   }
}
