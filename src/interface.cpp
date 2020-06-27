#include <iostream>
#include <stdlib.h>
#include "Moteur.h"
#include <typeinfo>

using namespace std;

string matrice[5][10];

void addObject(string object, int i, int j) {
  
  int prioObject=0;
  
  cout << object;
  if(object == "🕳 "){
    prioObject=5;
  } else if(object == "🏔 "){
    prioObject=4;
  }else if(object == " 👑 "){
    prioObject=3;
  }else if(object == " 🐜 "){
    prioObject=2;
  }else if(object == " 🥗 "){
    prioObject=1;
  }
  //cout << matrice[i][j];

  int prioMaxCellule=0;
  if(matrice[i][j] == " 🕳  "){
    prioMaxCellule=5;
  } else if(matrice[i][j] == " 🏔  "){
    prioMaxCellule=4;
  }else if(matrice[i][j] == " 👑 "){
    prioMaxCellule=3;
  }else if(matrice[i][j] == " 🐜 "){
    prioMaxCellule=2;
  }else if(matrice[i][j] == " 🥗 "){
    prioMaxCellule=1;
  }else if(matrice[i][j] == " ❎ "){
    prioMaxCellule=0;
  }
    //cout << prioObject <<" "<< prioMaxCellule;

  if(prioObject>prioMaxCellule) {
    if (prioObject >= 4 )
    matrice[i][j] = " "+object+" ";
    else {
        matrice[i][j] = object;
    }
  }
  //cout <<"  ======> ["<<i<<","<<j<<"] = "<<matrice[i][j]<<"\n";

}
string getObject(int i, int j) {
  return matrice[i][j];
}
void afficherEnvironnement(int row, int col) {
  int i,j;

  cout << "-----------------------------------------\n";
  cout << "\n";
  for(i=0; i < row; i++)
  {
    for(j = 0; j < col; j++)
    {
      cout << matrice[i][j];
    }
    cout << "\n\n";
  }
  cout <<"-----------------------------------------\n";
}

void initEnvironnement(int row, int col) {
  int i,j;

  for(i=0; i < row; i++)
  {
    for(j = 0; j < col; j++)
    {
      if (j==9) {
        matrice[i][j] = " ❎ ";
      } else {
        matrice[i][j] = " ❎ ";
      }
    }
  }
}
#include <time.h> 

int getRandInt(int a, int b){ 
  return rand()%(b-a)+a; 
}

void lauchGame ( int row, int col) {
    initEnvironnement(row, col);
    afficherEnvironnement(row, col);
}
/** Mettre à jour la matrice en fonction du terrain du moteur*/
void updateMatrice(std::vector< std::vector<Cellule> >& terrain) {

  //cout << "x [i] = "<<terrain.size();
  for (size_t i = 0; i < terrain.size(); i++)
  {
    //cout << "x [j] = "<<terrain[i].size();
    for (size_t j = 0; j < terrain[i].size(); j++)
    {
      std::vector<Entite*> entites  = terrain[i][j].getEntite();
      for (size_t e = 0; e < entites.size(); e++)
      {
        cout << "";
        if (entites[e]->getType() == "obstacle") {
          addObject("🕳 ", i,j);
        }
        if (entites[e]->getType() == "nourriture") {
          addObject(" 🥗 ", i,j);
        }
        if (entites[e]->getType() == "fourmi") {
          addObject(" 🐜 ", i,j);
        }
        if (entites[e]->getType() == "fourmiliere") {
          addObject("🏔 ", i,j);
        }
        /*if (entites[e]->getType() == "fourmi") {
          Fourmi tmpReine = dynamic_cast<Fourmi&>(*(entites[e]));
          if(tmpReine.getStatus() == REINE) {
            addObject(" 👑 ", i,j);
          }
        }*/
      }
    }
  }
}

void updateGame(int row, int col, int i, std::vector< std::vector<Cellule> >& t) {
  
  //updateMatrice(t);
  afficherEnvironnement(row,col);
}


#include <unistd.h>

int main (int argc, char *argv[]) {

  int row = 5;
  int col = 10;

  char* p;
  int fourmis=(int)(long)strtol(argv[1], &p, 10);
  int nourritures=(int)(long)strtol(argv[2], &p, 10);
  int obstacles=(int)(long)strtol(argv[3], &p, 10);

  Moteur moteur = Moteur(fourmis,nourritures,obstacles,15,15);

  lauchGame(row,col);
  int partie = 15;
for (size_t i = 0; i < partie; i++)
  {
    updateGame(row,col,i,moteur.getMatrice());
    moteur.next();
    
    for (size_t i = 0; i < moteur.getMatrice().size(); i++)
    {
      for (size_t j = 0; j < moteur.getMatrice()[i].size(); j++)
      {
        for (size_t k = 0; k < moteur.getMatrice()[i][j].getEntite().size(); k++)
        {
          //cout << moteur.getMatrice()[i][j].getEntite()[k]->getType()<<"\n";
          cout << "[Entite] : [" << i <<"]"<<"[" << j <<"]"<<" indice [" << k <<"]\n";
        }
      }
    }

    cout << "nombre d' entite : "<< moteur.getNombreEntite()<<"\n";

    cout << "Partie : "<< i << std::endl;
    
    usleep(999999);

    // Pour garder la dernière mise à jour
    if(i<partie) {
      system("clear");
    }
  }
}