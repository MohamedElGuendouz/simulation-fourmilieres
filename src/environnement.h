#include "fourmiliere.h"
#include <iostream>

struct synthese_cell {
    T_TYPE_CELLULE type;
    int pheromone;
    int x;
    int y;
    int seuilChoix;
};

class Environnement {
    private:
    int nombreObstacle;
    int nombreNourriture;
    int hauteur; //x
    int largeur; //y
    std::vector<std::vector<Cellule>> terrain;
    std::vector<Fourmi> fourmis;

    public:
    Environnement();
    Environnement(int h, int l, int nbObs, int nbNour);

    void initObstacleNourriture(bool cellulesSontLibres);
    void insereNewFourmiliere(int x, int y, int pm, int nm, int n);

    Cellule& getCellule(int x, int y);
    Cellule& getCelluleLibre(int x, int y);

    void nouveauTour();
    void deplaceFourmi();

    std::vector<synthese_cell> autour_cellule(int x, int y);

    void affiche();

    void compte() {
        int l = 0;
        int o = 0;
        int n = 0;
        for (int i=0 ; i < terrain.size();i++){
            for (int j = 0 ; j < terrain[i].size(); j++){
                if(terrain[i][j].getType() == LIBRE)  l++;
                else if (terrain[i][j].getType() == OBSTACLE)  o++;
                else if (terrain[i][j].getType() == NOURRITURE)  n++;
            }
        }
        std::cout<< "libre : "<< l <<std::endl;
        std::cout<< "obstacle : "<< o <<std::endl;
        std::cout<< "nourriture : "<< n <<std::endl;
    }
};

