#include "guerriere.h"

Guerriere::Guerriere(int x, int y):Fourmi(x,y) {
    this->deplacement = EXPLORATION;
}

int Guerriere::getParamDeplacement() const {
    int result;
    if(deplacement == EXPLORATION) {
        result= 40;//DEPLACEMENT_EXPLORATION;
    } else if(deplacement == RETOUR) {
        result=0;// DEPLACEMENT_RETOUR;
    }
    return result;
}