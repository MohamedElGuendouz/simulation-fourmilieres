#include <iostream>
#include <vector>

#include "entite.h"
#include "fourmi.h"
#include "nourriture.h"
#include "obstacle.h"
#include "cellule.h"

class Moteur {

    private:
        std::vector<Fourmi> fourmis;
        std::vector<Nourriture> nourritures;
        std::vector<std::vector<Cellule>> terrain;
        std::vector<Obstacle> obstacles;

        unsigned int populationMax;
        unsigned int nourritureMax;

        int nbTour;

        bool partieEnCours;

    public:
        Moteur(std::vector<Fourmi> vf, std::vector<Nourriture>  vn, std::vector<std::vector<Cellule>>  vc,std::vector<Obstacle>  vo, int popMax, int nourMax){
            this->fourmis = vf;
            this->nourritures = vn;
            this->terrain = vc;
            this->obstacles = vo;
            populationMax = popMax;
            nourritureMax = nourMax;
            this->partieEnCours = true;
        }

        /** Cette méthode est utilisé pour passer a la prochaine partie **/
        void next();

        /** Cette méthode est utilisé pour mettre à jour la matrice du terrain **/
        void evolutionDuTerrain();

        /** Cette méthode est utilisé pour deplacer les fourmis du terrain **/
        void deplacerLesFourmis();

        /** Cette méthode est utilisé pour supprimé de la matrice les entités mortes **/ 
        void garbageEntite();

        void updateMatrice();

        void reccupererLaNourriture(std::vector<Fourmi> fourmis, std::vector<Nourriture> nourritures);


        void updateValues();

        void deplacerFourmi(Fourmi *f);

        std::vector<Cellule> updateAffichage();

        std::vector<Fourmi> getFourmis() const;

        std::vector<Obstacle> getObstacles() const;

        std::vector<Nourriture> getNourritures() const;
        
        std::vector<std::vector<Cellule>> getMatrice() const;

        std::vector<Cellule> getCelluleAutour(int i, int j) const;
        std::vector<Cellule> getCelluleAutour(Cellule c) const;

        std::vector<Cellule> getCelluleADroite(int i, int j) const;
        std::vector<Cellule> getCelluleADroite(Cellule c) const;

        std::vector<Cellule> getCelluleAGauche(int i, int j) const;
        std::vector<Cellule> getCelluleAGauche(Cellule c) const;

        std::vector<Cellule> getCelluleEnBas(int i, int j) const;
        std::vector<Cellule> getCelluleEnBas(Cellule c) const;

        std::vector<Cellule> getCelluleEnHaut(int i, int j) const;
        std::vector<Cellule> getCelluleEnHaut(Cellule c) const;

        
        
};