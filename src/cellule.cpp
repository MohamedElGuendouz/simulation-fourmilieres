#include <typeinfo>
#include "cellule.h"

Cellule::Cellule(){
    x = 0;
    y = 0;
    this->type = LIBRE;
}

void Cellule::setType(T_TYPE_CELLULE type) {
    this->type = type;
}

T_TYPE_CELLULE Cellule::getType() {
    return this->type;
}

bool Cellule::containsFourmi(){
    bool result = false;
    for (unsigned int i=0; i < this->contenu.size();i++)
    {
       if(typeid(Fourmi) == typeid(this->contenu[i]))
        {
            result = true;;
        }
    }
    return result;
}

std::vector<Nourriture*> Cellule::getNourritures() {
    /** Pour chaque nourriture de la cellule */
    std::vector<Nourriture*> tmp ;
    for (unsigned int i=0; i < this->contenu.size();i++)
    {
       if(typeid(Nourriture) == typeid(this->contenu[i]))
        {
            tmp.push_back(&(dynamic_cast<Nourriture&>(*this->contenu[i])));
        }
    }
    return tmp;
}

std::vector<Fourmi*> Cellule::getFourmi() {
    /** Pour chaque nourriture de la cellule */
    std::vector<Fourmi*> tmp ;
    for ( unsigned int i=0; i < this->contenu.size();i++)
    {
       if(typeid(Fourmi) == typeid(this->contenu[i]))
        {
            tmp.push_back(&(dynamic_cast<Fourmi&>(*this->contenu[i])));
        }
    }
    return tmp;
}