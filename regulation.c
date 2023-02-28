#include "regulation.h"

/***
 * @function cette fonction permet de calculer la puissance nécessaire pour arrivé à la consigne de l'utilisateur
 * @param regul int : 1->ToR 2->PID | ce paramètre correspond au mode que l'on souhaite utilisé
 * @param consigne float | ce paramètre correspond à la consigne donnée par l'utilisateur
 * @param tabT float* | ce paramètre correspond à l'historique de tous les températures de la pièce
 * @param nT int | ce paramètre correspond au nombre de températures qu'il y'a dans l'historique
 * @return float | retourne la puissance du chauffage à utiliser pour arrivé à la consigne de l'utilisateur
 */
float regulationTest(int regul, float consigne, float* tabT, int nT){
    float cmd;
    float proportionnel;
    float integral;
    float derive;
    if (regul == 1){
        if (consigne > tabT[nT-1]){
            cmd = 40.0;
        }
        else{
            cmd = 0.0;
        }
    }
    if (regul == 2){
        proportionnel = consigne - tabT[nT - 1];
        for (int j = 0; j < nT; ++j){
            integral += consigne - tabT[j];
        }
        for (int j = 0; j < (nT - 1); ++j){
            derive += tabT[j + 1] - tabT[j];
        }
        cmd = proportionnel*KP + integral*KI + derive*KD;
    }
    return cmd;
}

