#include <vector>
#include "guerriere.h"

typedef enum { LIBRE, OBSTACLE, NOURRITURE, FOURMILIERE } T_TYPE_CELLULE ;

class Cellule {
    private:
    
    int x;
    int y;
    int pheromones;
    T_TYPE_CELLULE type;
    std::vector<Fourmi *> contenu;

    protected:
    int nourriture;
    
    public:
    Cellule();
    Cellule( int coordX, int coordY, T_TYPE_CELLULE type );

    void addContenu(Fourmi ent);
    std::vector<Fourmi *>& getContenu();

    int getPheromone() const;

    T_TYPE_CELLULE getType() const;

    void setType(T_TYPE_CELLULE type);
    void setNourriture(int n);

    int retirer_nourriture(int n);
};