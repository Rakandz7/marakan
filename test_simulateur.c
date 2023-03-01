#include <stdio.h>
#include <stdlib.h>
#include "simulateur.h"
#include "consigne.h"
#include "regulation.h"
#include "visualisationC.h"
#include "visualisationT.h"

int main(){
    remove(".verrouData");
    remove(".verrouConsigne");
	temp_t temperature;
	temperature.exterieure = 14.0;
	temperature.interieure = 15.0;
    float* tabT = NULL;
    tabT = (float *) malloc(100 * sizeof(float));
    int nT = 0;
    float cmd = 0;
    float consPrec = 19.0;
    float cons = 19.0;
    int tmp;
	struct simParam_s*  monSimulateur = simConstruct(temperature); // creation du simulateur, puissance intialisé
	while(cons >= 5.0){

        temperature = simCalc(cmd,monSimulateur);
        if (nT == 99){
            tmp = 0;
            for (int i = 0; i < 99; ++i) {
                tabT[i] = tabT[i + 1];
            }
            tabT[99] = temperature.interieure;
        }
        else{
            tmp = 1;
            tabT[nT] = temperature.interieure;
        }
        visualisationT(temperature);
        cons = consigne(consPrec);
        consPrec = cons;
        cmd = regulationTest(2,cons, tabT, nT+1);
        if (tmp){
            nT++;
        }
        visualisationC(cmd);
	}
    free(tabT);
	simDestruct(monSimulateur); // destruction de simulateur
	return EXIT_SUCCESS;
}