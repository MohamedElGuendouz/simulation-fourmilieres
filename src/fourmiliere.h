#include <vector>
#include "cellule.h"

class Fourmiliere {
    private:
        int populationMax;
        int nourritureMax;
        int nourriture;
        std::vector<int> fourmis;
        Cellule* cell;

    public:
        Fourmiliere(int pm,int nm, int n, Cellule* ptrCell){
            populationMax = pm;
            nourritureMax = nm;
            nourriture = n;
            cell = ptrCell;
        }
};