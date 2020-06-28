#include "Moteur.h"

int Moteur::getNombreEntite(){
    int result =  fourmis.size() + nourritures.size() + obstacles.size();
    return result;
}

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
    for(unsigned int i=0; i<fourmis.size(); i++) {
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
    bool trouve = true;
    int intFourmis=0;
    while(trouve){
        trouve = false;     
        while (intFourmis<fourmis.size() and !trouve) {
            if(fourmis[intFourmis].getLifeValue() == 0) {
                trouve = true;
            } else {
                intFourmis++;
            }        
        }
        if(trouve) fourmis.erase(fourmis.begin()+intFourmis);
    }

    /** Supprimer les nourritures avec une valeur a 0 */
    bool trouve = true;
    int intNourriture=0;
    while(trouve){
        trouve = false;     
        while (intNourriture<nourritures.size() and !trouve) {
            if(nourritures[intNourriture].getValeur() == 0) {
                trouve = true;
            } else {
                intNourriture++;
            }        
        }
        if(trouve) nourritures.erase(nourritures.begin()+intNourriture);
    }
    
    /** Diminution des pheromones */
    for(unsigned int i=0; i<terrain.size(); i++) {
        for( int j=0; i<terrain.size(); i++) {
          terrain[i][j].downPheromone();
      }
    }
}

void Moteur::reccupererLaNourriture(int i, int x, int y)
{
        /** on verifie si la fourmi a atteint sa capacite max pour porter de la nourriture */
        if (fourmis[i].getNourriture() != fourmis[i].getNourritureMax())
        {
            ///// LA FOURMI PREND DE LA NOURRITURE AVANT DE PARTIR SI ELLE PEUT //////

            /** on calcule la capacite restante de la fourmi */
            int deltaMax = int(fourmis[i].getNourritureMax() - fourmis[i].getNourriture());

            /** permet de connaitre la nourriture prises par la fourmi */
            int deltaAdd = 0;

            /** Pour chaque nourriture de la cellule */
            for (unsigned int j=0; j < nourritures.size();j++)
            {
                /** Tant qu'il reste de la nourriture dans cette objet que l on a pas depasser la capacite de la fourmi */
                if(nourritures[j].getAbs() == x and nourritures[j].getOrd() == y and deltaMax > deltaAdd and nourritures[j].getValeur()>0){
                    if (deltaMax - deltaAdd >= nourritures[j].getValeur()){
                        deltaAdd += nourritures[j].getValeur();
                        nourritures[j].setValeur(0);
                    }else{
                        nourritures[j].setValeur(nourritures[j].getValeur() + deltaAdd - deltaMax);
                        deltaAdd = deltaMax;
                    }
                }
            }
            fourmis[i].setNourriture(fourmis[i].getNourriture()+deltaAdd);
            fourmis[i].setExplo(RAVITAILLEMENT);
        }
}

/** Cette méthode est utilisé pour deplacer les fourmis du terrain */
void Moteur::deplacerLesFourmis()
{
    /** on regarde toutes les cellules du terrain */
    for (unsigned int i = 0; i < this->fourmis.size(); i++)
    {
        int x = fourmis[i].getAbs();
        int y = fourmis[i].getOrd();
        /** on regarde si la cellule contiens de la nourriture et une ou plusieurs fourmi(s) */
        if (containsNourriture(x,y))
        {
            /** Les fourmis reccupere la nourriture */
            reccupererLaNourriture(i,x,y);
        }

        deplacerFourmi(i);
            
    }
}

void Moteur::deplacerFourmi(int i){
    int oldX = fourmis[i].getAbs();
    int oldY = fourmis[i].getOrd();
    std::vector<Cellule*> cellules = getCelluleAutour(oldX,oldY);
    if (fourmis[i].modeExploration() == EXPLORATION)
    {
        bool findCellule = false;
        for (unsigned int j = 0; j < cellules.size(); j++)
        {
            /** si une cellule contient de la nourriture, elle se deplace dessus */
            if (!findCellule)
            {
                if (containsNourriture(cellules[j]->getAbs(),cellules[j]->getOrd()))
                {
                    findCellule = true;
                    deposePheromone(40,cellules[j]);
                    fourmis[i].setAbs(cellules[j]->getAbs());
                    fourmis[i].setOrd(cellules[j]->getOrd());
                    cellules[j]->addEntite(&fourmis[i]);
                    removeReferenceCellule(cellules[j], &fourmis[i]);
                }
            }
        }
        int j = rand() %cellules.size();
        int nbB = 0;
        while (!findCellule)
        {
            if (!containsObstacle(cellules[j]->getAbs(),cellules[j]->getOrd()))
            {
                findCellule = true;
                deposePheromone(20,cellules[j]);
                fourmis[i].setAbs(cellules[j]->getAbs());
                fourmis[i].setOrd(cellules[j]->getOrd());
                cellules[j]->addEntite(&fourmis[i]);
                removeReferenceCellule(cellules[j], &fourmis[i]);
            } else if(nbB > cellules.size())findCellule = true;
            else {
                if(j == cellules.size()-1) j = 0;
                else j++;
            }
            nbB++;
        }
    }
    if (fourmis[i].modeExploration() == RAVITAILLEMENT)
    {
        Cellule* celluleMaxPheromone = cellules[0];
        int total = 0;
        for (unsigned int j = 0; j < cellules.size(); j++) total+= cellules[j]->getPheromone();

        int tirage = rand()%total;
        int somme = 0;
        unsigned int j = 0;
        int indice = -1;
        bool trouve = false;
        while(j < cellules.size() and !trouve)
        {
            somme += cellules[j]->getPheromone();
            if(tirage <= somme) {
                if (cellules[j]->contientPasObstacle())
                {
                    indice = j;
                }
                trouve = true;
            }
            j++;
        }
        if (indice >=0){
            deposePheromone(5,cellules[indice]);
            fourmis[i].setAbs(cellules[indice]->getAbs());
            fourmis[i].setOrd(cellules[indice]->getOrd());
            cellules[indice]->addEntite(&fourmis[i]);
            removeReferenceCellule(cellules[indice], &fourmis[i]);
        }
    }
}

std::vector<Cellule*> Moteur::getCelluleAutour( unsigned int i,unsigned int j) {
    std::vector<Cellule*> result;
    if(i>0){
        result.push_back(&terrain[i-1][j]);
    }
    if(i<terrain.size()-1){
        result.push_back(&terrain[i+1][j]);
    }
    if(j>0){
        result.push_back(&terrain[i][j-1]);
    }
    if(j<terrain[i].size()-1){
        result.push_back(&terrain[i][j+1]);
    }
    return result;
}

void Moteur::deposePheromone(int i, Cellule* c){
    c->addPheromone(i);
}

void Moteur::removeReferenceCellule(Cellule* c, Entite* f){
    c->removeEntite(f);
}

std::vector<Fourmi> Moteur::getFourmis() {
    return this->fourmis;
}

bool Moteur::containsFourmi(int i, int j) const{
    bool result = false;
    int k = 0;
    while(k<fourmis.size() and !result){
        if(fourmis[k].getAbs() == i and fourmis[k].getOrd() == j) result = true;
        k++;
    }
    return result;
}

bool Moteur::containsReine(int i, int j) const{
    bool result = false;
    int k = 0;
    while(k<reines.size() and !result){
        if(reines[k].getAbs() == i and reines[k].getOrd() == j) result = true;
        k++;
    }
    return result;
}


bool Moteur::containsObstacle(int i, int j) const{
    bool result = false;
    int k = 0;
    while(k<obstacles.size() and !result){
        if(obstacles[k].getAbs() == i and obstacles[k].getOrd() == j) result = true;
        k++;
    }
    return result;
}

bool Moteur::containsNourriture(int i, int j) const{
    bool result = false;
    int k = 0;
    while(k<nourritures.size() and !result){
        if(nourritures[k].getAbs() == i and nourritures[k].getOrd() == j) result = true;
        k++;
    }
    return result;
}

bool Moteur::containsFoumiliere(int i, int j) const{
    bool result = false;
    int k = 0;
    while(k<fourmilieres.size() and !result){
        if(fourmilieres[k].getAbs() == i and fourmilieres[k].getOrd() == j) result = true;
        k++;
    }
    return result;
}

int Moteur::getSommeNourriture(int x, int y){
    int somme = 0;
    int k = 0;
    while(k<nourritures.size()){
        if(fourmilieres[k].getAbs() == x and fourmilieres[k].getOrd() == y) somme += nourritures[k].getValeur();
        k++;
    }
    return somme;
}

int Moteur::getPheromoneCellule(int x, int y){
    return terrain[x][y].getPheromone();
}