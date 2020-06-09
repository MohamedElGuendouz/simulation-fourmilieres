#include "cellule.h"

Cellule::Cellule(){
    x = 0;
    y = 0;
    this->type = LIBRE;
}
Cellule::Cellule(int coordX, int coordY, T_TYPE_CELLULE type ){
    x = coordX;
    y = coordY;
    this->type = type;
}

void Cellule::addContenu(Entite ent){
    contenu.push_back(ent);
}

void Cellule::setType(T_TYPE_CELLULE type) {
    this->type = type;
}

T_TYPE_CELLULE Cellule::getType() const {
    return type;
}