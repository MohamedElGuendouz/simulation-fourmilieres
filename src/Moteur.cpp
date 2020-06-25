#include "Moteur.h"

/** Cette méthode est utilisé pour passer a la prochaine partie **/
void Moteur::next()
{
    if (this->partieEnCours)
    {
        evolutionDuTerrain();
    }
}

/** Cette méthode est utilisé pour mettre à jour la matrice du terrain **/
void Moteur::evolutionDuTerrain()
{
    updateMatrice();
    deplacerLesFourmis();
}

/** Cette méthode est utilisé pour mettre à jour la matrice les entités mortes **/
void Moteur::updateMatrice()
{
    updateValues();
    garbageEntite();
}

/** Cette méthode est utilisé pour mettre à jour les données des entités **/
void Moteur::updateValues()
{
    /** Mettre à jour la vie de chaque fourmis */
    for( int i=0; i<fourmis.size(); i++) {
        fourmis[i].downLifeValue();
        fourmis[i].upYear();
        fourmis[i].changeEtat();
        fourmis[i].changeStatus();
        fourmis[i].changeExploration();
    }
}

/** Cette méthode est utilisé pour supprimé de la matrice les entités mortes **/
void Moteur::garbageEntite()
{
    std::vector<Fourmi>::iterator it;
    /** Supprimer les fourmis mortes */
    int intFourmis=0;
    for (it = fourmis.begin(); it != fourmis.end(); it++,intFourmis++) {
        if(fourmis[i].getLifeValue() == 0) {
            fourmis.erase(it);
        }
    }

    std::vector<Nourriture>::iterator ite;
    /** Supprimer les nourritures avec une valeur a 0 */
    int intNourriture=0;
    for (ite = nourritures.begin(); ite != nourritures.end(); ite++,intNourriture++) {
        if(nourritures[intNourriture].getValeur() == 0) {
            nourritures.erase(ite);
        }
    }
    
    /** Diminution des pheromones */
    for( int i=0; i<terrain.size(); i++) {
        for( int j=0; i<terrain.size(); i++) {
          terrain[i][j].downPheromone();
      }
    }
}

void Moteur::reccupererLaNourriture(std::vector<Fourmi> fourmis, std::vector<Nourriture> nourritures)
{

    /** Pour chaque fourmis de la cellule */
    for (int i=0; i< fourmis.size(); i++)
    {
        /** on verifie si la fourmi a atteint sa capacite max pour porter de la nourriture */
        if (fourmis[i].getNourriture() == fourmis[i].getNourritureMax())
        {
            // Elle laisse la nourriture dans la cellule
            deplacerFourmi(&fourmis[i]);
        }
        /** Sinon */
        else
        {
            ///// LA FOURMI PREND DE LA NOURRITURE AVANT DE PARTIR SI ELLE PEUT //////

            /** on calcule la capacite restante de la fourmi */
            int deltaMax = int(fourmis[i].getNourritureMax() - fourmis[i].getNourriture());

            /** permet de connaitre la nourriture prises par la fourmi */
            int deltaAdd = 0;

            /** Pour chaque nourriture de la cellule */
            for (int i=0; i < nourritures.size();i++)
            {
                /** Tant qu'il reste de la nourriture dans cette objet que l on a pas depasser la capacite de la fourmi */
                while (nourritures[i].getValeur() > 0 and deltaMax > deltaAdd)
                {
                    /** Si la valeur de l'objet est egale a la valeur à ajoute, on l'ajoute la totalite */
                    if (nourritures[i].getValeur() == deltaMax)
                    {
                        /** On ajoute la valeur de l'objet Nourriture */
                        deltaAdd = deltaAdd + nourritures[i].getValeur();

                        /** On met a jour la valeur de l'objet Nourriture a 0 */
                        nourritures[i].setValeur(0);
                    }
                    /** Sinon on ajoute un par un de la nourriture à la fourmi */
                    else
                    {
                        /** La fourmi reccupere la nourriture */
                        deltaAdd = deltaAdd + 1;

                        /** On met a jour la valeur de l'objet Nourriture */
                        nourritures[i].setValeur(nourritures[i].getValeur() - 1);
                    }
                }
            }
            fourmis[i].setNourriture(fourmis[i].getNourriture()+deltaAdd);
        }
    }
}

/** Cette méthode est utilisé pour deplacer les fourmis du terrain */
void Moteur::deplacerLesFourmis()
{
    /** on regarde toutes les cellules du terrain */
    for (int i = 0; i < this->terrain.size(); i++)
    {
        for (int j = 0; j < this->terrain[i].size(); j++)
        {
            /** on regarde si la cellule contiens de la nourriture et une ou plusieurs fourmi(s) */
            if (this->terrain[i][j].containsFourmi() and this->terrain[i][j].contientNourriture())
            {
                /** Les fourmis reccupere la nourriture */
                reccupererLaNourriture(this->terrain[i][j].getFourmi(), this->terrain[i][j].getNourriture());

                /** on deplace les fourmis */
                deplacerFourmi(this->terrain[i][j].getFourmi());
            }
            /** Si la cellule contient une ou plusieurs fourmis mais pas de nourriture */
            else if (this->terrain[i][j].containsFourmi())
            {
                std::vector<Fourmi>::iterator it;
                int itn=0;
                /** pour chaque fourmi de la cellule*/
                for (it = this->terrain[i][j].getFourmi().begin(); it != this->terrain[i][j].getFourmi().end(); it++,itn++) {
                    /** on deplace la fourmi suivant son mode de deplacement */
                    deplacerFourmi(this->terrain[i][j].getFourmi()[itn]);
                }
            }
        }
    }
}

void Moteur::deplacerFourmi(Fourmi* f)
{
    for (int i = 0; i < this->fourmis.size(); i++)
    {
        if (f == &this->fourmis[i])
        {
            std::vector<Cellule> cellules = getCelluleAutour(f->getAbs(), f->getOrd());
            if (f->modeExploration() == EXPLORATION)
            {
                bool findCellule = false;
                for (int j = 0; j < cellules.size(); j++)
                {
                    /** si une cellule contient de la nourriture, elle se deplace dessus */
                    if (!findCellule)
                    {
                        if (cellules[j].contientNourriture())
                        {
                            findCellule = true;
                            deposePheromone(1,&cellules[j]);
                            cellules[j].addEntite(*f);
                            removeReferenceCellule(&cellules[j], f);
                        }
                    }
                }
                if (!findCellule)
                {
                    for (int j = 0; j < cellules.size(); j++)
                    {
                        /** si une cellule contient de la nourriture, elle se deplace dessus */
                        if (!findCellule)
                        {
                            if (cellules[j].contientPasObstacle())
                            {
                                findCellule = true;
                                deposePheromone(1,&cellules[j]);
                                cellules[j].addEntite(*f);
                                removeReferenceCellule(&cellules[j], f);
                            }
                        }
                    }
                }
            }
            if (f->modeExploration() == RAVITAILLEMENT)
            {
                Cellule* celluleMaxPheromone = &cellules[0];
                for (int j = 0; j < cellules.size(); j++)
                {
                    if (cellules[j].contientPasObstacle())
                    {
                        if (cellules[j].getPheromone() > celluleMaxPheromone->getPheromone())
                        {
                            celluleMaxPheromone = &cellules[j];
                        }
                    }
                }
                deposePheromone(1,celluleMaxPheromone);
                celluleMaxPheromone->addEntite(*f);
                removeReferenceCellule(celluleMaxPheromone, f);
            }
        }
    }
}

void removeReferenceCellule(Cellule* c, Fourmi* f)
{
    std::vector<Entite>::iterator it; 
    std::vector<Entite> vectorEntite = c->getEntite();
    int i =0;
    for (it = vectorEntite.begin(); it != vectorEntite.end(); it++)
    {
        if (&vectorEntite[i] == f)
        {
            vectorEntite.erase(it);
        }
        i++;
    }
}

void deposePheromone(int pheromone, Cellule* c)
{
    c->addPheromone(pheromone);
}