#include <stdio.h>
#include <stdlib.h>
#include "simulateur.h"
#include "consigne.h"
#include "regulation.h"
#include "visualisationC.h"
#include "visualisationT.h"

int main(){
    // gestion d'érreur si les fichiers .verrouData .verrouConsigne ne se sont pas supprimé
    remove(".verrouData"); // suppression du fichier .verrouData
    remove(".verrouConsigne"); // suppression du fichier .verrouConsigne
	temp_t temperature; // initialisation de la température
	temperature.exterieure = 14.0; // initialisation de la température extérieure à 14.0°C
	temperature.interieure = 15.0; // initialisation de la température intérieure à 15.0°C
    float* tabT = NULL; // initialisation du tableau de température à NULL
    tabT = (float *) malloc(100 * sizeof(float)); // initialisation du tableau de température d'une taille de 100 float
    int nT = 0; // initialisation du nombre de température dans le tableau à 0
    float cmd = 0; // initialisation de la commande du chauffage à 0%
    float consPrec = 19.0; // initialisation de la consigne précédente à 19.0°C
    float cons = 19.0; // initialisation de la consigne à 19.0°C
    int tmp; // initialisation d'une variable temporaire
	struct simParam_s*  monSimulateur = simConstruct(temperature); // creation du simulateur, puissance intialisé
    // programme qui tourne jusqu'a ce que la consigne soit égale à 5°C
	while(cons != 5.0){
        temperature = simCalc(cmd,monSimulateur); // calcule de la température grâce à la commande en % du chauffage via simCalc
        // vérification si le tableau est plein
        if (nT == 99){
            // tableau plein
            tmp = 0; // variable temporaire qui vaut 0 -> arrêt de l'augmentation de nT
            for (int i = 0; i < 99; ++i) {
                tabT[i] = tabT[i + 1]; // décalage de toutes les températures d'une case
            }
            tabT[99] = temperature.interieure; // attribuation de la dernière case du tableau à la dernière température
        }
        else{
            // tableau non-plein
            tmp = 1;  // variable temporaire qui vaut 1 -> augmentation de nT
            tabT[nT] = temperature.interieure; // attribuation de la case actuel du tableau à la dernière température
        }
        visualisationT(temperature); // écriture de la température intérieur et extérieur dans le fichier data.txt
        cons = consigne(consPrec); // lecture de la consigne dans le fichier consigne.txt
        consPrec = cons; // attribuation de la consigne précédente à la consigne actuel
        cmd = regulationTest(2,cons, tabT, nT+1); // calcule de la commande en fonction de la consigne et des températures
        // vérification temporaire qui vaut 1
        if (tmp){
            nT++; // augmentation de nT
        }
        visualisationC(cmd); // écriture de l'allumage ou non dans le fichier data.txt
	}
    free(tabT); // libération de la mémoiore du tableau tabT
	simDestruct(monSimulateur); // destruction de simulateur
	return EXIT_SUCCESS;
}