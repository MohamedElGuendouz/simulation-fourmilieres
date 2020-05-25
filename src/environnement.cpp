#include "environnement.h"

Environnement::Environnement(){
    largeur = 100;
    hauteur = 50;
    nombreObstacle = 1000;
    nombreNourriture = 500;

    terrain.resize(hauteur);
    for (int i=0 ; i < terrain.size();i++){
        terrain[i].resize(largeur);
        for (int j = 0 ; j < terrain[i].size(); j++){
            terrain[i][j] = Cellule( i , j , LIBRE);
        }
    }

    initObstacleNourriture(true);
}

void Environnement::initObstacleNourriture(bool cellulesSontLibres){
    if(!cellulesSontLibres) {

    }
    int x,y;
    for (int i = 0; i<nombreObstacle;i++){
        x = rand() % hauteur;
        y = rand() % largeur;
        terrain[x][y].setType(OBSTACLE);
    }
    for (int i = 0; i<nombreNourriture;i++){
        x = rand() % hauteur;
        y = rand() % largeur;
        terrain[x][y].setType(NOURRITURE);
    }
}

Cellule Environnement::getCellule(int x, int y) const {
    return terrain[x][y];
}

void Environnement::affiche(){
    for (int i=0 ; i < terrain.size();i++){
        std::cout<<std::endl;
        for (int j = 0 ; j < terrain[i].size(); j++){
            if(terrain[i][j].getType() == LIBRE)  std::cout<<"_";
            else if (terrain[i][j].getType() == OBSTACLE)  std::cout<<"X";
            else if (terrain[i][j].getType() == NOURRITURE)  std::cout<<"O";
        }
    }
    std::cout<<std::endl;
}