#include "regulation.h"

/***
 * @brief cette fonction permet de calculer la puissance nécessaire pour arrivé à la consigne de l'utilisateur
 * @param regul int : 1->ToR 2->PID | ce paramètre correspond au mode que l'on souhaite utilisé
 * @param consigne float | ce paramètre correspond à la consigne donnée par l'utilisateur
 * @param tabT float* | ce paramètre correspond à l'historique de tous les températures de la pièce
 * @param nT int | ce paramètre correspond au nombre de températures qu'il y'a dans l'historique
 * @return float | retourne la puissance du chauffage à utiliser pour arrivé à la consigne de l'utilisateur
 */
float regulationTest(int regul, float consigne, float* tabT, int nT){
    float cmd; // puissance du chauffage en %
    float proportionnel; // porportionnel du PID
    float integral; // intégrale du PID
    float derive; // dérivé du PID
    // vérification de l'allumage du chauffage ou non
    if (consigne > tabT[nT-1]){
        // chauffage allumé
        // vérification de mode Tout ou Rien (ToR) ou du mode Proportionnel Intégrale Dérivé (PID)
        if (regul == 1){
            // mode ToR
            cmd = 40.0;
        }
        if (regul == 2){
            // mode PID
            proportionnel = consigne - tabT[nT - 1]; // calcule du proportionnel (dernière erreur)
            for (int i = 0; i < nT; ++i){ // parcours de toutes les températures
                integral += consigne - tabT[i]; // calcule de l'intégrale (somme de toutes les erreurs)
            }
            derive = (consigne - tabT[nT - 1]) - (consigne - tabT[nT - 2]); // calcule de la dérivé (différence entre les deux dernière erreurs)
            cmd = KP * proportionnel + KI * integral + KD * derive; // calcule du PID (Kp * P + Ki * I + Kd * D)
            // vérification de la puissance minimum et maximum
            if (cmd > 100.0){
                // puissance maximum atteinte (100% maximum)
                cmd = 100.0; // attribuation de la puissance du chauffage à 100%
            }
            if (cmd < 0.0){
                // puissance minimum atteinte (0% minimum)
                cmd = 0.0; // attribuation de la puissance du chauffage à 0%
            }
        }
    }
    else{
        // chauffage eteint
        cmd = 0.0; // attribuation de la puissance du chauffage à 0%
    }
    return cmd; // retourne la puissance du chauffage en %
}

