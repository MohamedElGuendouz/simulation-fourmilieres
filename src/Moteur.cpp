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
    /** Supprimer les fourmis mortes */
    for( int i=0; i<fourmis.size(); i++) {
        if(fourmis[i].getLifeValue() == 0) {
            fourmis[i].erase(i);
        }
    }

    /** Supprimer les nourritures avec une valeur a 0 */
    for( int i=0; i<nourritures.size(); i++) {
        if(nourritures[i].getValeur() == 0) {
            nourritures[i].erase(i);
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
                while (nourritures[i].getValeur() > 0 and detlaMax > deltaAdd)
                {
                    /** Si la valeur de l'objet est egale a la valeur à ajoute, on l'ajoute la totalite */
                    if (nourritures[i].getValeur() == detlaMax)
                    {
                        /** On ajoute la valeur de l'objet Nourriture */
                        detlaAdd = detlaAdd + nourritures[i].getValeur();

                        /** On met a jour la valeur de l'objet Nourriture a 0 */
                        nourritures[i].getValeur() = 0;
                    }
                    /** Sinon on ajoute un par un de la nourriture à la fourmi */
                    else
                    {
                        /** La fourmi reccupere la nourriture */
                        deltaAdd = deltaAdd + 1;

                        /** On met a jour la valeur de l'objet Nourriture */
                        nourritures[i].setValeur(nourriture.getValeur() - 1);
                    }
                }
            }
        }
        tmpFourmis.ajouterNourriture(deltaAdd);
    }
}

/** Cette méthode est utilisé pour deplacer les fourmis du terrain */
void Moteur::deplacerLesFourmis()
{
    /** on regarde toutes les cellules du terrain */
    for (i in this->terrain)
    {
        /** on regarde si la cellule contiens de la nourriture et une ou plusieurs fourmi(s) */
        if (this->terrain[i].containsFourmi() and this->terrain[i].containsNourriture())
        {
            /** Les fourmis reccupere la nourriture */
            reccupererLaNourriture(this->terrain[i].getFourmi(), this->terrain[i].getNourriture())

                /** on deplace les fourmis */
                deplacerFourmi(tmpFourmis);
        }
        /** Si la cellule contient une ou plusieurs fourmis mais pas de nourriture */
        else if (this->terrain[i].containsFourmi())
        {
            /** On reccupere les fourmis */
            tmpFourmis = this->terrain[i].getFourmi();

            /** pour chaque fourmi de la cellule*/
            for (fourmi in tmpFourmis)
            {
                /** on deplace la fourmi suivant son mode de deplacement */
                deplacerFourmi(fourmi);
            }
        }
        else
        {
            // On n'applique pas de deplacement dans cette cellule
        }
    }
}

void deplacerFourmi(*Fourmi f)
{
    for (fourmi in this->fourmis)
    {
        if (*f == *fourmi)
        {
            cellules = getCelluleAutour(f->getAbs(), f->getOrd());
            if (*f.modeExploration() == "Explorateur")
            {
                bool findCellule = false;
                for (c in cellules)
                {
                    /** si une cellule contient de la nourriture, elle se deplace dessus */
                    if (!findCellule)
                    {
                        if (c.contientNourriture())
                        {
                            findCellule = true;
                            deposePheromone(1,*c);
                            c.addEntite(*f);
                            removeReferenceCellule(*c, *f);
                        }
                    }
                }
                if (!findCellule)
                {
                    for (c in cellules)
                    {
                        /** si une cellule contient de la nourriture, elle se deplace dessus */
                        if (!findCellule)
                        {
                            if (c.contientPasObstacle())
                            {
                                findCellule = true;
                                deposePheromone(1,*c);
                                *c.addEntite(*f);
                                removeReferenceCellule(*c, *f);
                            }
                        }
                    }
                }
            }
            if (*f.modeExploration() == "Ravitaillement")
            {
                *Cellule celluleMaxPheromone = *cellules[0];
                for (c in cellules)
                {
                    if (c.contientPasObstacle())
                    {
                        if (c.pheromone > celluleMaxPheromone.pheromone)
                        {
                            celluleMaxPheromone = c;
                        }
                    }
                }
                deposePheromone(1,*celluleMaxPheromone);
                celluleMaxPheromone.addEntite(*f);
                removeReferenceCellule(*celluleMaxPheromone, *f);
            }
        }
    }
}

void removeReferenceCellule(*Cellule c, *Fourmi f)
{
    vectorEntite = c.getEntite();
    for (int i = 0; i < vectorEntite.size(); i++)
    {
        if (&vectorEntite[i] == &c)
        {
            vectorEntite.erase(i);
        }
    }
}

void deposePheromone(int pheromone, *Cellule c)
{
    c->addPheromone(pheromone);
}