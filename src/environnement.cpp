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

    insereNewFourmiliere(hauteur/2,largeur/2,200,1000,100);
    initObstacleNourriture(true);
}

Environnement::Environnement(int h, int l, int nbObs, int nbNour){
    largeur = l;
    hauteur = h;
    nombreObstacle = nbObs;
    nombreNourriture = nbNour;

    terrain.resize(hauteur);
    for (int i=0 ; i < terrain.size();i++){
        terrain[i].resize(largeur);
        for (int j = 0 ; j < terrain[i].size(); j++){
            terrain[i][j] = Cellule( i , j , LIBRE);
        }
    }

    insereNewFourmiliere(hauteur/2,largeur/2,200,1000,100);
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
        getCelluleLibre(x,y).setType(OBSTACLE);
    }
    for (int i = 0; i<nombreNourriture;i++){
        x = rand() % hauteur;
        y = rand() % largeur;
        Cellule* retenue = & getCelluleLibre(x,y);
        retenue->setType(NOURRITURE);
        retenue->setNourriture(500);
    }
}

void Environnement::insereNewFourmiliere(int x, int y, int pm, int nm, int n){
    if (x >= hauteur or x < 0 or y < 0 or y > largeur) throw 0; //out of range
    terrain[x][y].addContenu(Fourmiliere(x,y,pm,nm,n));
    terrain[x][y].setType(FOURMILIERE);
}

Cellule& Environnement::getCellule(int x, int y) {
    if (x >= hauteur or x < 0 or y < 0 or y > largeur) throw 0; //out of range
    return terrain[x][y];
}

Cellule& Environnement::getCelluleLibre(int x, int y) {
    while (terrain[x][y].getType() != LIBRE){
        if (y<largeur-1) y++;
        else if (x<hauteur-1) { x++; y=0;}
        else { x=0 ; y=0;}
    }
    return terrain[x][y];
}

void Environnement::affiche(){
    for (int i=0 ; i < terrain.size();i++){
        std::cout<<std::endl;
        for (int j = 0 ; j < terrain[i].size(); j++){
            if(terrain[i][j].getType() == LIBRE)  std::cout<<"_";
            else if (terrain[i][j].getType() == OBSTACLE)  std::cout<<"X";
            else if (terrain[i][j].getType() == NOURRITURE)  std::cout<<"O";
            else if (terrain[i][j].getType() == FOURMILIERE)  std::cout<<"F";
        }
    }
    std::cout<<std::endl;
}