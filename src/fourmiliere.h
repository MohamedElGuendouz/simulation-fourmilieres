#include <vector>
#include "cellule.h"

class Fourmiliere : public Cellule {
    private:
        unsigned int populationMax;
        unsigned int nourritureMax;
        std::vector<Fourmi> contenu;

    public:
        Fourmiliere(int x, int y, int pm,int nm, int n):Cellule(x,y,FOURMILIERE){
            populationMax = pm;
            nourritureMax = nm;
            this->nourriture = n;
        }

        void ajoutNourriture(int n);
        bool consommeNourriture(int n);
};