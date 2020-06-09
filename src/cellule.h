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

    void addContenu(Entite ent);

    Cellule getSuivant() const;//droite puis retour à la ligne puis retour a premiere cellule
    Cellule getDessus() const;
    Cellule getDessous() const;
    Cellule getDroite() const;
    Cellule getGauche() const;

    T_TYPE_CELLULE getType() const;

    void setType(T_TYPE_CELLULE type);
};