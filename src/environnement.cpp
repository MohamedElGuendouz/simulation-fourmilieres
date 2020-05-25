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
        //ajouter traitement remise à libre de toutes les cellules
    }
    int x,y;
    for (int i = 0; i<nombreObstacle;i++){
        x = rand() % hauteur;
        y = rand() % largeur;
        getCelluleLibre(x,y);
        terrain[x][y].setType(OBSTACLE);
    }
    for (int i = 0; i<nombreNourriture;i++){
        x = rand() % hauteur;
        y = rand() % largeur;
        getCelluleLibre(x,y);
        terrain[x][y].setType(NOURRITURE);
    }
}

Cellule Environnement::getCellule(int x, int y) const {
    return terrain[x][y];
}

void Environnement::getCelluleLibre(int& x, int& y) const {
    //std::cout<<x<<" "<<y;
    while (terrain[x][y].getType() != LIBRE){
        if (y<largeur-1) y++;
        else if (x<hauteur-1) { x++; y=0;}
        else { x=0 ; y=0;}
    }
    //std::cout<<" sortie "<<x<<" "<<y<<std::endl;
    //return terrain[x][y];
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