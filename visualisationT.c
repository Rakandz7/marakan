#include "visualisationT.h"

/***
 * @function Cette fonction permet de d'afficher sur l'interface IHM la température interne et externe via le fichier data.txt
 * @param myTemp struct -> float & float | ce paramètre correspond aux température interne et externe
 * @return void
 */
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
        float tempExt; // température extérieur
        float tempInt; // température intérieur
        char ioChauff[10]; // Chaine vide pour  l'allumage du chauffage true ou false
        if (data != NULL){
            fscanf(data, "%f", &tempExt); // on lit la première ligne
            fscanf(data, "%f", &tempInt); // on lit la deuxième ligne
            fscanf(data, "%s", ioChauff); // on lit la trosième ligne
            fclose(data);
        }
        else{
            fprintf(stderr, "Le fichier data.txt ne s'est pas ouvert (visualisation C)\n");
            exit(0);
        }
        data = fopen("data.txt", "w");
        if (data != NULL){
            fprintf(data, "%f\n", myTemp.exterieure); // on écrit la première ligne
            fprintf(data, "%f\n", myTemp.interieure); // on écrit la deuxième ligne
            fprintf(data, "%s\n", ioChauff); // on écrit la troisième ligne
            fclose(data);
        }
       fclose(verrouData);
       int error = remove(".verrouData");
       if (error == 0){
           printf(".verrouData remove successfully\n");
       }
       else{
           printf("unable to remove .verrouData\n");
       }
   }
}
