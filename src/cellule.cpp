#include "cellule.h"

Cellule::Cellule(){
    x = 0;
    y = 0;
    this->type = LIBRE;
    pheromones = 0;
    nourriture = 0;
}
Cellule::Cellule(int coordX, int coordY, T_TYPE_CELLULE type ){
    x = coordX;
    y = coordY;
    this->type = type;
    pheromones = 0;
    nourriture = 0;
}

void Cellule::addContenu(Fourmi ent){
    contenu.push_back(ent);
}

T_TYPE_CELLULE Cellule::getType() const {
    return type;
}

void Cellule::setType(T_TYPE_CELLULE type) {
    this->type = type;
}

void Cellule::setNourriture(int n){
    this->nourriture = n;
}

int Cellule::retirer_nourriture(int n){
    if (nourriture <= n) {
        n = nourriture;
        nourriture = 0;
        this->type = LIBRE;
    } else {
        nourriture -= n;
    }
    return n;
}