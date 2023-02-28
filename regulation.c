#include <stdio.h>
#include <stdlib.h>
#include "regulation.h"

float regulationTest(int regul, float consigne, float* tabT, int nT){
    float cmd;
    if (regul){
        if (consigne > tabT[nT-1]){
            cmd = 40.0;
        }
        else{
            cmd = 0.0;
        }
    }
    return cmd;
}
