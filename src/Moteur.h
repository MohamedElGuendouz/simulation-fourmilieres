#include <iostream>
#include <vector>

//#include "fourmi.h"
//#include "nourriture.h"
#include "obstacle.h"
#include "cellule.h"
#include <time.h> 

class Moteur {

    private:
        int hauteur;
        int largeur;
        
        std::vector<Fourmi> fourmis;
        std::vector<Nourriture> nourritures;
        std::vector< std::vector<Cellule> > terrain;
        std::vector<Obstacle> obstacles;

        unsigned int populationMax;
        unsigned int nourritureMax;

        int nbTour;

        bool partieEnCours;

    public:
        int getRandInt(int a, int b){ 
            return rand()%(b-a)+a; 
        }
        
        Moteur(int vf, int vn ,int vo, int popMax, int nourMax, int hauteur, int largeur)
        {
            this->hauteur = hauteur;
            this->largeur = largeur;

            terrain.resize(hauteur);
            for (size_t i = 0; i < hauteur; i++)
            {
                terrain[i].resize(largeur);
                for (size_t j = 0; j < largeur; j++)
                {
                    terrain[i][j] = Cellule(i,j,0,0,LIBRE);
                }
            }
            
            fourmis.clear();
            for (size_t i = 0; i < vf; i++)
            {
                int xtmp = getRandInt(0,hauteur-1);
                int ytmp = getRandInt(0,largeur-1);
                
                fourmis.push_back(Fourmi(xtmp,ytmp,FOURMI,OUVRIERE));
                terrain[xtmp][ytmp].addEntite(&fourmis[i]);
            }
            
            nourritures.clear();
            for (size_t i = 0; i < vn; i++)
            {
                int xtmp = getRandInt(0,hauteur-1);
                int ytmp = getRandInt(0,largeur-1);

                nourritures.push_back(Nourriture(xtmp,ytmp,getRandInt(1,10)));
                terrain[xtmp][ytmp].addEntite(&nourritures[i]);
            }
            
            obstacles.clear();
            for (size_t i = 0; i < vo; i++)
            {
                int xtmp = getRandInt(0,hauteur-1);
                int ytmp = getRandInt(0,largeur-1);

                obstacles.push_back(Obstacle(xtmp,ytmp));
                terrain[xtmp][ytmp].addEntite(&obstacles[i]);
            }

            populationMax = popMax;
            nourritureMax = nourMax;
            this->partieEnCours = true;
        }

        int getHauteur(){return hauteur;}
        int getLargeur(){return largeur;}

        int getNombreEntite();

        /** Cette méthode est utilisé pour passer a la prochaine partie **/
        void next();

        /** Cette méthode est utilisé pour mettre à jour la matrice du terrain **/
        void evolutionDuTerrain();

        /** Cette méthode est utilisé pour deplacer les fourmis du terrain **/
        void deplacerLesFourmis();

        /** Cette méthode est utilisé pour supprimé de la matrice les entités mortes **/ 
        void garbageEntite();

        void updateMatrice();

        void reccupererLaNourriture(std::vector<Fourmi*> fourmis, std::vector<Nourriture*> nourritures);

        void deposePheromone(int i, Cellule* c);

        void removeReferenceCellule(Cellule* c, Fourmi* f);

        void updateValues();

        void deplacerFourmi(Fourmi* f);

        std::vector<Cellule> updateAffichage();

        std::vector<Fourmi> getFourmis();

        std::vector<Obstacle> getObstacles() const;

        std::vector<Nourriture> getNourritures() const;
        
        std::vector< std::vector<Cellule> >& getMatrice() {return terrain;};

        bool containsFourmi(int i, int j) const;
        bool containsObstacle(int i, int j) const;
        bool containsNourriture(int i, int j) const;

        std::vector<Cellule> getCelluleAutour(unsigned int i,unsigned int j) const;
        std::vector<Cellule> getCelluleAutour(Cellule c) const;

};