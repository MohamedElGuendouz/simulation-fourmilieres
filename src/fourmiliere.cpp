#include "fourmiliere.h"

void Fourmiliere::ajoutNourriture(int n){
    if(nourriture + n >= nourritureMax) {
        nourriture = nourritureMax;
    } else {
        nourriture += n;
    }
}

bool Fourmiliere::consommeNourriture(int n){
    if(nourriture - n < 0) {
        return false;
    } else {
        nourriture -= n;
        return true;
    }
}