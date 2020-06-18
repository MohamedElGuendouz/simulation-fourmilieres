#include <vector>
#include "entite.h"
#include "singleton.h"

class Fourmiliere : public Entite, Singleton<Fourmiliere> {
    friend class Singleton<Fourmiliere>; 
    private:
        unsigned int populationMax;
        unsigned int nourritureMax;
        unsigned int nourriture;
        std::vector<Entite> contenu;

    public:
        Fourmiliere(int x, int y, int pm,int nm, int n){
            this->x = x;
            this->y = y;
            populationMax = pm;
            nourritureMax = nm;
            nourriture = n;
        }

        void ajoutNourriture(int n);
        bool consommeNourriture(int n);
};