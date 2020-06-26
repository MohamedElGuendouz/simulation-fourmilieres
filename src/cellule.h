#include <vector>
#include "fourmiliere.h"
#include "fourmi.h"
#include "nourriture.h"

typedef enum { LIBRE, OBSTACLE, NOURRITURE, FOURMILIERE } T_TYPE_CELLULE ;

class Cellule {
  private:
    int x;
    int y;
    int pheromones;
    int nourriture;
    T_TYPE_CELLULE type;
    std::vector<Entite*> contenu;

  public:
    Cellule();
    Cellule(int coordX, int coordY,int p,int n, T_TYPE_CELLULE t):x(coordX),y(coordY),pheromones(p),nourriture(n),type(t){};

    void addEntite(Entite* ent){
      this->contenu.push_back(ent);
    }
    void removeEntite(Entite* ent){
      std::vector<Entite*>::iterator it; 
      int i =0;
      for (it = contenu.begin(); it != contenu.end(); it++)
      {
          if (contenu[i] == ent)
          {
              contenu.erase(it);
          }
          i++;
      }
    }

    std::vector<Entite*> getEntite(){return contenu;}

    void addPheromone(int qte) {pheromones += qte;}

    T_TYPE_CELLULE getType() const;

    void setType(T_TYPE_CELLULE type);
    int getPheromone(){return pheromones;}

    void downPheromone() {pheromones--;}

    bool contientNourriture() {if(nourriture>0) return true; return false;}
    bool contientPasObstacle() {if(type == OBSTACLE)return false;return true;}

    bool containsFourmi();

    std::vector<Nourriture*> getNourritures();
    std::vector<Fourmi*> getFourmi();
};