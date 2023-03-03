#include <unistd.h>
#include <stdio.h>
#include "visualisationC.h"

/***
 * @brief cette fonction permet de d'afficher sur l'interface IHM si le chauffage est sur On ou Off via le fichier data.txt
 * @param puissance_f float | ce paramètre correspond au % de puissance du chaffage utilisé
 * @return void
 */
void visualisationC(float puissance_f){
   // vérification de l'existance du fichier .verrouData
    if (access(".verrouData",F_OK) != -1){
        // fichier .verrouData existe
        return; // arrêt de la fonction
    }
    else {
        // fichier .verrouData n'exsite pas
        FILE* verrouData= NULL; // initialisation de verrouData à NULL
        verrouData = fopen(".verrouData", "w"); // création du fichier .verrouData
        // vérification de la création du fichier .verrouData
        if (verrouData == NULL) {
            // fichier .verrouData ne s'est pas créer
            fprintf(stderr, "le fichier .verrouData n'a pas pu s'ouvrir\n"); // affichage dans le terminale de l'erreur
            exit(0);
        }
        else{
            // fichier .verrouData s'est créer
            FILE* data = NULL; // initialisation de data à NULL
            data = fopen("data.txt","r"); // ouverture du fichier data.txt en lecture
            float tempExt; // variable qui récupère la température extérieur
            float tempInt; // variable qui récupère la température intérieur
            // vérification de l'ouverture du fichier data.txt
            if (data != NULL){
                // fichier data.txt s'est ouvert
                fscanf(data, "%f", &tempExt); // lecture de la température extérieur en °C
                fscanf(data, "%f", &tempInt); // lecture de la température intérieur en °C
                fclose(data); // fermeture du fichier data.txt
            }
            else{
                // fichier data.txt ne s'est pas ouvert
                fprintf(stderr, "Le fichier data.txt ne s'est pas ouvert (visualisation C)\n"); // affichage dans le terminale de l'erreur
                exit(0);
            }
            data = fopen("data.txt","w"); // ouverture du fichier data.txt en écriture
            // vérification de l'ouverture du fichier data.txt
            if (data != NULL){
                // fichier data.txt s'est ouvert
                fprintf(data, "%f\n", tempExt); // écriture de la température extérieur en °C
                fprintf(data, "%f\n", tempInt); // écriture de la température intérieur en °C
                // vérification de l'allumage du chauffage
                if(puissance_f == 0){
                    // chauffage eteint
                    fprintf(data, "false"); // écriture du chaffage eteint
                }
                else {
                    // chauffage allumé
                    fprintf(data, "true"); // écriture du chaffage allumé
                }
                fclose(data); // fermeture du fichier data.txt
            }
            else{
                // fichier data.txt ne s'est pas ouvert
                fprintf(stderr, "Le fichier data.txt ne s'est pas ouvert (visualisation C)\n"); // affichage dans le terminale de l'erreur
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
