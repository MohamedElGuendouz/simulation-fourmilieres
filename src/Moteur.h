#include <iostream>
#include <vector>

//#include "fourmi.h"
//#include "nourriture.h"
#include "obstacle.h"
#include "cellule.h"
#include <time.h> 

class Moteur {

    private:
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
        
        Moteur(int vf, int vn ,int vo, int popMax, int nourMax)
        {
            for (size_t i = 0; i < 5; i++)
            {
                std::vector<Cellule> vectorTmp;
                for (size_t j = 0; j < 10; j++)
                {
                    Cellule celluletmp = Cellule(i,j,0,0,LIBRE);
                    vectorTmp.push_back(celluletmp);
                }
                terrain.push_back(vectorTmp);
            }
            
            for (size_t i = 0; i < vf; i++)
            {
                int xtmp = getRandInt(0,4);
                int ytmp = getRandInt(0,9);
                Fourmi fourmitmp = Fourmi(xtmp,ytmp,FOURMI,OUVRIERE);
                
                fourmis.push_back(fourmitmp);
                terrain[xtmp][ytmp].addEntite(&fourmis[i]);
            }
            
            for (size_t i = 0; i < vn; i++)
            {
                int xtmp = getRandInt(0,4);
                int ytmp = getRandInt(0,9);
                Nourriture nourrituretmp = Nourriture(xtmp,ytmp,getRandInt(0,10));

                nourritures.push_back(nourrituretmp);
                terrain[xtmp][ytmp].addEntite(&nourrituretmp);
            }
            
            for (size_t i = 0; i < vo; i++)
            {
                int xtmp = getRandInt(0,4);
                int ytmp = getRandInt(0,9);

                Obstacle obstacletmp = Obstacle(getRandInt(0,4),getRandInt(0,9));
                obstacles.push_back(obstacletmp);
                terrain[xtmp][ytmp].addEntite(&obstacletmp);
            }

            populationMax = popMax;
            nourritureMax = nourMax;
            this->partieEnCours = true;
        }

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

        std::vector<Cellule> getCelluleAutour(unsigned int i,unsigned int j) const;
        std::vector<Cellule> getCelluleAutour(Cellule c) const;

        std::vector<Cellule> getCelluleADroite(int i, int j) const;
        std::vector<Cellule> getCelluleADroite(Cellule c) const;

        std::vector<Cellule> getCelluleAGauche(int i, int j) const;
        std::vector<Cellule> getCelluleAGauche(Cellule c) const;

        std::vector<Cellule> getCelluleEnBas(int i, int j) const;
        std::vector<Cellule> getCelluleEnBas(Cellule c) const;

        std::vector<Cellule> getCelluleEnHaut(int i, int j) const;
        std::vector<Cellule> getCelluleEnHaut(Cellule c) const;     
};