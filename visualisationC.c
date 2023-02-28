#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "visualisationC.h"


void visualisationC(float puissance_f){
   // Verification de l'existance du fichier .verrouData
    if (access (".verrouData",F_OK)!= -1){
        // Fichier existe
        return;
    }
    else {
        // Fichier n'exsite pas
        FILE *verrouData= NULL;
        verrouData = fopen(".verrouData", "w");
        if (verrouData == NULL) {
            fprintf(stderr, "le fichier .verrouData n'a pas pu s'ouvrir\n");
            exit(0);
        }
        FILE* data = NULL;
        data = fopen("data.txt","r");
        float tempExt;
        float tempInt;
        if (data != NULL){
            fscanf(data, "%f", &tempExt); // on lit la première ligne
            fscanf(data, "%f", &tempInt); // on lit la deuxième ligne
            fclose(data);
        }
        else{
            fprintf(stderr, "Le fichier data.txt ne s'est pas ouvert\n");
            exit(0);
        }
        data = fopen("data.txt","w");
        fprintf(data, "%f", tempExt);
        fprintf(data, "%f", tempInt);
        if(puissance_f == 0){
            fprintf(data, "false");
            fclose(data);
        }
        else {
            fprintf(data, "true");
            fclose(data);
        }
        remove(".verrouData");
    }
}
