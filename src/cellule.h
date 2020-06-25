#include <vector>
#include "fourmiliere.h"
#include "fourmi.h"

typedef enum { LIBRE, OBSTACLE, NOURRITURE, FOURMILIERE } T_TYPE_CELLULE ;

class Cellule {
  private:
    int x;
    int y;
    int pheromones;
    int nourriture;
    T_TYPE_CELLULE type;
    std::vector<Entite> contenu;

  public:
    Cellule();
    Cellule(int coordX, int coordY, T_TYPE_CELLULE type );

    void addEntite(Entite ent){
      this->contenu.push_back(ent);
    }

    std::vector<Entite> getEntite(){return contenu;}

    void addPheromone(int qte) {pheromones += qte;}

    T_TYPE_CELLULE getType() const;

    void setType(T_TYPE_CELLULE type);
    int getPheromone(){return pheromones;}
    int getNourriture(){return nourriture;}

    void downPheromone() {pheromones--;}

    bool contientNourriture() {if(nourriture>0) return true; return false;}
    bool contientPasObstacle() {if(type == OBSTACLE)return false;return true;}

    bool containsFourmi();

    std::vector<Fourmi> getFourmi();
};