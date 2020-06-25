#include <typeinfo>
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

void Cellule::setType(T_TYPE_CELLULE type) {
    this->type = type;
}

T_TYPE_CELLULE Cellule::getType() const {
    return type;
}

std::vector<Fourmi> Cellule::getFourmi() {
    /** Pour chaque nourriture de la cellule */
    std::vector<Fourmi> tmp ;
    for (int i=0; i < this->contenu.size();i++)
    {
       if(typeid(Fourmi) == typeid(this->contenu[i]))
        {
            tmp.push_back(dynamic_cast<const Fourmi&>(this->contenu[i]));
        }
    }
    return tmp;
}