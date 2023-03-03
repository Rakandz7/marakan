#include "visualisationT.h"

/***
 * @biref cette fonction permet de d'afficher sur l'interface IHM la température interne et externe via le fichier data.txt
 * @param myTemp struct -> float & float | ce paramètre correspond aux température interne et externe
 * @return void
 */
void visualisationT(temp_t myTemp){
    // vérification de l'existance du fichier .verrouData
   if(access(".verrouData", F_OK) != -1){
       // fichier .verrouData existe
        return; // arrêt de la fonction
   }
   else{
       // fichier .verrouData n'exsite pas
        FILE* verrouData = NULL; // initialisation de verrouData à NULL
        verrouData = fopen(".verrouData", "w"); // création du fichier .verrouData
       // vérification de la création du fichier .verrouData
        if (verrouData == NULL){
            // fichier .verrouData ne s'est pas créer
            fprintf(stderr, "le fichier .verrouData n'a pas pu s'ouvrir\n"); // affichage dans le terminale de l'erreur
            exit(0);
        }
        else{
            // fichier .verrouData s'est créer
            FILE* data = NULL; // initialisation de data à NULL
            data = fopen("data.txt", "r"); // ouverture du fichier data.txt en lecture
            float tmp; // variable qui récupère la température extérieur et intérieur (variable temporaire)
            char ioChauff[10]; // variable qui récupère si le chauffage est allumé ou eteint
            // vérification de l'ouverture du fichier data.txt
            if (data != NULL){
                // fichier data.txt s'est ouvert
                fscanf(data, "%f", &tmp); // lecture de la température extérieur en °C
                fscanf(data, "%f", &tmp); // lecture de la température intérieur en °C
                fscanf(data, "%s", ioChauff); // lecture qui récupère si le chauffage est allumé ou eteint
                fclose(data); // fermeture du fichier data.txt
            }
            else{
                // fichier data.txt ne s'est pas ouvert
                fprintf(stderr, "Le fichier data.txt ne s'est pas ouvert (visualisation T)\n"); // affichage dans le terminale de l'erreur
                exit(0);
            }
            data = fopen("data.txt", "w"); // ouverture du fichier data.txt en écriture
            // vérification de l'ouverture du fichier data.txt
            if (data != NULL){
                // fichier data.txt s'est ouvert
                fprintf(data, "%f\n", myTemp.exterieure); // écriture de la température extérieur en °C
                fprintf(data, "%f\n", myTemp.interieure); // écriture de la température intérieur en °C
                fprintf(data, "%s\n", ioChauff); // écriture qui récupère si le chauffage est allumé ou eteint
                fclose(data); // fermeture du fichier data.txt
            }
            else{
                // fichier data.txt ne s'est pas ouvert
                fprintf(stderr, "Le fichier data.txt ne s'est pas ouvert (visualisation T)\n"); // affichage dans le terminale de l'erreur
                exit(0);
            }
            fclose(verrouData); // fermeture du fichier .verrouData
            int error = remove(".verrouData"); // suppression du fichier .verrouData
            // vérification de la fermeture de .verrouData
            if (error != 0){
                // fichier .verrouConsigne ne s'est pas supprimé
                printf("unable to remove .verrouData\n"); // affichage dans le terminale de l'erreur
            }
        }
   }
}
