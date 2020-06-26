#include <iostream>
#include <stdlib.h>
//#include "Moteur.h"

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

      cout << "-----------------------------------------\n";
      cout << "Ajout des composants dans l'environnement\n";
      cout << "-----------------------------------------\n";

    for (int i=0; i<obs; i++) {
      addObject("🕳 ", getRandInt(0,row),getRandInt(0,col));
    }

    for (int i=0; i<nour; i++) {
      addObject(" 🥗 ", getRandInt(0,row),getRandInt(0,col));
    }

    for (int i=0; i<10; i++) {
      addObject(" 🐜 ", getRandInt(0,row),getRandInt(0,col));
    }

    addObject("🏔 ", getRandInt(0,row),getRandInt(0,col));

    addObject(" 👑 ", getRandInt(0,row),getRandInt(0,col));

    
    afficherEnvironnement(row, col);
}
/** Mettre à jour la matrice en fonction du terrain du moteur*/
void updateMatrice() {
  //code
}

void updateGame(int row, int col, int i) {
  
  updateMatrice();
    //cout <<"\n";
    //addObject("🕳 ", 2,2);
    //addObject(" 🥗 ", 2,2);
    //addObject(" 🐜 ", 2,2);
    //addObject("🏔 ", 2,2);
    //addObject(" 👑 ", 2,2);
    //cout <<"\n";
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

  /**std::vector<Fourmi> *vf;
  for (size_t i = 0; i < fourmis; i++)
  {
    vf[i] = new Fourmi();
  }
  
  std::vector<Nourriture> *vn;
  for (size_t i = 0; i < nourritures; i++)
  {
    vn[i] = new Fourmi();
  }
  
  std::vector<Obstacle>  *vo;
  for (size_t i = 0; i < obstacles; i++)
  {
    vo[i] = new Obstacle();
  }*/
  int popMax=5;
  int nourMax=10;

  /**std::vector< std::vector<Cellule> > *vc;
  for (size_t i = 0; i < row; i++)
  {
    for (size_t j = 0; i < col; i++)
    {
      vc[i][j].push_back(Cellule());
    }
  }*/

  //Moteur moteur = new Moteur(vf,vn,vc,vo,popMax,nourMax);
  lauchGame(row,col,10,5,0.95);
  int partie = 15;
  for (size_t i = 0; i < partie; i++)
  {
    updateGame(row,col,i);
    usleep(999999);

    // Pour garder la dernière mise à jour
    if(i<partie) {
      system("clear");
    }
  }


}