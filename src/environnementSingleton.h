/*  
#include <iostream>
class EnvironnementSingleton
{
private:
static EnvironnementSingleton* instance;
EnvironnementSingleton();

int nombreObstacle;
int nombreNourriture;
int hauteur; //x
int largeur; //y
std::vector< std::vector<Cellule>> terrain;
int id;

public:
    static EnvironnementSingleton* getInstance();
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


EnvironnementSingleton* EnvironnementSingleton::instance = 0;
EnvironnementSingleton* EnvironnementSingleton::getInstance()
{
if (instance == 0)
    {
        instance = new EnvironnementSingleton();
    }
return instance;
}
EnvironnementSingleton::EnvironnementSingleton()
{}

EnvironnementSingleton::EnvironnementSingleton(){
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

EnvironnementSingleton::EnvironnementSingleton(int h, int l, int nbObs, int nbNour){
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

void EnvironnementSingleton::initObstacleNourriture(bool cellulesSontLibres){
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
        getCelluleLibre(x,y).setType(NOURRITURE);
    }
}

void EnvironnementSingleton::insereNewFourmiliere(int x, int y, int pm, int nm, int n){
    if (x >= hauteur or x < 0 or y < 0 or y > largeur) throw 0; //out of range
    terrain[x][y].addContenu(Fourmiliere(x,y,pm,nm,n));
    terrain[x][y].setType(FOURMILIERE);
}

Cellule& EnvironnementSingleton::getCellule(int x, int y) {
    if (x >= hauteur or x < 0 or y < 0 or y > largeur) throw 0; //out of range
    return terrain[x][y];
}

Cellule& EnvironnementSingleton::getCelluleLibre(int x, int y) {
    while (terrain[x][y].getType() != LIBRE){
        if (y<largeur-1) y++;
        else if (x<hauteur-1) { x++; y=0;}
        else { x=0 ; y=0;}
    }
    return terrain[x][y];
}

void EnvironnementSingleton::affiche(){
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

void EnvironnementSingleton::setId(int i){
  this->id = i;
}

int EnvironnementSingleton::getId(){
  return this->id;
}

*/