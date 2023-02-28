#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "visualisationC.h"


   void visualisationC(float puissance_f){
    if (access (".verrouData",F_OK)!= -1){

       }
    else {
        FILE *verrouData= NULL;
        verrouData = fopen(".verrouData", "w");
        if (verrouData == NULL) {
            fprintf(stderr, "le fichier n'a pas pu etre creer  \n");
            exit(0);

        }
        FILE* data = NULL;
        data = fopen("data.txt","r");
        float tempExt;
        float tempInt;
        char ioChauff;
        if (data != NULL){
            fscanf(data, "‰f", &tempExt); // on lit la première ligne
            fscanf(data, "%f", &tempInt); // on lit la deuxième ligne
            fscanf(data, "%s", ioChauff); // on lit la trosième ligne
            fclose(data);
        }
        else{
            printf("Impossible d'ouvrir data.txt");
        }
        data = fopen("data.txt","w");
        fprintf(data,"%f",tempExt);
        fprintf(data,"%f",tempInt);
        if(puissance_f==0){
            fprintf(data,"false");
            fclose(data);
        }
        else {
            fprintf(data,"true");
            fclose(data);
        }
        remove(".verrouData");
    }




   }
            	
   
   }
