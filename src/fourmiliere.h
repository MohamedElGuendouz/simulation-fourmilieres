#include <vector>
#include "entite.h"

class Fourmiliere : public Entite {
    private:
        unsigned int populationMax;
        unsigned int nourritureMax;
        unsigned int nourriture;
        std::vector<Entite> contenu;

    public:
        Fourmiliere(int x, int y, int pm,int nm, int n):Entite(x,y,"fourmiliere"){

            populationMax = pm;
            nourritureMax = nm;
            nourriture = n;
        }

        void ajoutNourriture(int n);
        bool consommeNourriture(int n);

};