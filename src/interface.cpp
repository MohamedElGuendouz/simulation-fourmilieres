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
  cout << matrice[i][j];

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
    cout << prioObject <<" "<< prioMaxCellule;

  if(prioObject>prioMaxCellule) {
    if (prioObject >= 4 )
    matrice[i][j] = " "+object+" ";
    else {
        matrice[i][j] = object;
    }
  }
  cout <<"  ======> ["<<i<<","<<j<<"] = "<<matrice[i][j]<<"\n";

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

void lauchGame ( int row, int col, int obs, int nour, double absphero) {
    initEnvironnement(row, col);
    /*  cout << "-----------------------------------------\n";
      cout << "Ajout des composants dans l'environnement\n";
      cout << "-----------------------------------------\n";

    for (int o=0; o<obs; o++) {
      addObject("🕳 ", getRandInt(0,row),getRandInt(0,col));
    }

    for (int n=0; n<nour; n++) {
      addObject(" 🥗 ", getRandInt(0,row),getRandInt(0,col));
    }

    for (int f=0; f<10; f++) {
      addObject(" 🐜 ", getRandInt(0,row),getRandInt(0,col));
    }

    addObject("🏔 ", getRandInt(0,row),getRandInt(0,col));

    addObject(" 👑 ", getRandInt(0,row),getRandInt(0,col));
    */
    afficherEnvironnement(row, col);
}
/** Mettre à jour la matrice en fonction du terrain du moteur*/
void updateMatrice(std::vector< std::vector<Cellule> >& terrain) {
  for (size_t i = 0; i < terrain.size(); i++)
  {
    for (size_t j = 0; j < terrain[i].size(); j++)
    {
      std::vector<Entite*> entites  = terrain[i][j].getEntite();
      for (size_t e = 0; e < entites.size(); e++)
      {
        if (typeid(entites[e]) == typeid(Obstacle)) {
          addObject("🕳 ", getRandInt(i,j),getRandInt(i,j));
        }

        if (typeid(entites[e]) == typeid(Nourriture)) {
          addObject(" 🥗 ", getRandInt(i,j),getRandInt(i,j));
        }

        if (typeid(entites[e]) == typeid(Fourmi)) {
          addObject(" 🐜 ", getRandInt(i,j),getRandInt(i,j));
        }

        if (typeid(entites[e]) == typeid(Fourmiliere)) {
          addObject("🏔 ", getRandInt(i,j),getRandInt(i,j));
        }
        if (typeid(entites[e]) == typeid(Fourmi)) {
          Fourmi tmpReine = dynamic_cast<Fourmi&>(*(entites[e]));
          if(tmpReine.getStatus() == REINE) {
            addObject(" 👑 ", getRandInt(i,j),getRandInt(i,j));
          }
        }
      }
    }
  }
}

void updateGame(int row, int col, int i, std::vector< std::vector<Cellule> >& t) {
  
  updateMatrice(t);
  afficherEnvironnement(row,col);
  std::cout << "Partie : "<< i << std::endl;
}


#include <unistd.h>

int main () {
  int row, col;
  row = 5;
  col = 10;
  int fourmis=5;
  int nourritures=5;
  int obstacles=5;

  Moteur moteur = Moteur(10,5,2,15,15);

  lauchGame(row,col,2,5,0.95);
  int partie = 15;
  for (size_t i = 0; i < partie; i++)
  {
    updateGame(row,col,i,moteur.getMatrice());
    usleep(999999);

    // Pour garder la dernière mise à jour
    if(i<partie) {
      system("clear");
    }
  }


}