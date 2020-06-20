#include "cellule.h"
#include <iostream>

class Environnement : public Singleton<Environnement>{
    friend class Singleton<Environnement>; 
    private:
    int nombreObstacle;
    int nombreNourriture;
    int hauteur; //x
    int largeur; //y
    std::vector< std::vector<Cellule> > terrain;
    int id;
    friend class Singleton<Environnement>; 

    public:
    Environnement();
    Environnement(int h, int l, int nbObs, int nbNour);
    void setId(int i);
    int getId();
    void initObstacleNourriture(bool cellulesSontLibres);
    void insereNewFourmiliere(int x, int y, int pm, int nm, int n);

    Cellule& getCellule(int x, int y);
    Cellule& getCelluleLibre(int x, int y);

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