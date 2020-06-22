#include <vector>
#include "fourmiliere.h"

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
    Cellule( int coordX, int coordY, T_TYPE_CELLULE type );

    void addEntite(Entite ent);
    void addContenu(Entite ent);

    std::vector<Entite> getEntite(){return contenu;}

    void addPheromone(int qte) {pheromones += qte;}

    T_TYPE_CELLULE getType() const;

    void setType(T_TYPE_CELLULE type);

    void downPheromone() {pheromones--;}
};