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
    terrain[x][y] = Fourmiliere(x,y,pm,nm,n);
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

std::vector<synthese_cell> Environnement::autour_cellule(int x, int y){
    std::vector<synthese_cell> result;
    synthese_cell cell;
    if(x-1 >= 0 and terrain[x-1][y].getType() != OBSTACLE){
        cell.type = terrain[x-1][y].getType();
        cell.pheromone = terrain[x-1][y].getPheromone();
        cell.x = x-1;
        cell.y = y;
        result.push_back(cell);
    }
    if(x+1 < hauteur and terrain[x+1][y].getType() != OBSTACLE){
        cell.type = terrain[x+1][y].getType();
        cell.pheromone = terrain[x+1][y].getPheromone();
        cell.x = x+1;
        cell.y = y;
        result.push_back(cell);
    }
    if(y-1 >= 0 and terrain[x][y-1].getType() != OBSTACLE){
        cell.type = terrain[x][y-1].getType();
        cell.pheromone = terrain[x][y-1].getPheromone();
        cell.x = x;
        cell.y = y-1;
        result.push_back(cell);
    }
    if(y+1 < largeur and terrain[x][y+1].getType() != OBSTACLE){
        cell.type = terrain[x][y+1].getType();
        cell.pheromone = terrain[x][y+1].getPheromone();
        cell.x = x;
        cell.y = y+1;
        result.push_back(cell);
    }
    return result;
}

void Environnement::nouveauTour(){
    for (int i=0 ; i < terrain.size();i++){
        for (int j = 0 ; j < terrain[i].size(); j++){
            //les actions sur les différents attributs de la cellule
            //pheromones diminuent

            //les actions sur les fourmis dans la cellule
            std::vector<Fourmi>& fourmis = terrain[i][j].getContenu();
            for (int k=0; k< fourmis.size();i++){
                int x = fourmis[k].getAbs();
                int y = fourmis[k].getOrd();
                int deplacement = fourmis[k].getParamDeplacement();
                bool cherche_nourriture = fourmis[k].getChercheNourriture();

                if (deplacement > 0) {
                    bool case_trouve = false;
                    int xfutur, yfutur;
                    std::vector<synthese_cell> synthese = autour_cellule(i,j);
                    if (cherche_nourriture){
                        int l = 0;
                        while(!case_trouve and l < synthese.size()){
                            if(synthese[l].type = NOURRITURE){
                                xfutur = synthese[l].x;
                                yfutur = synthese[l].y;
                                case_trouve = true;
                            }
                            l++;
                        }                      
                    } 
                    if(!case_trouve){
                        int totalPhero = 0;
                        int somme = 0;
                        for(int l = 0 ; l< synthese.size();l++){
                            totalPhero += synthese[l].pheromone;
                        }
                        for(int l = 0 ; l< synthese.size();l++){
                            somme += deplacement / synthese.size() + (100-deplacement)* synthese[l].pheromone / totalPhero;
                            synthese[l].seuilChoix = somme;
                        }
                        int tirage = rand() %100;
                        int indice = 0;
                        while (tirage > synthese[indice].seuilChoix and indice < synthese.size()-1){
                            indice++;
                        }
                    }
                }
            }
            //laisse des pheromones
            //ramasse ou depose nourriture
        }
    }
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