#include <iostream>
#include <stdlib.h>
#include "Moteur.h"

using namespace std;

string matrice[5][10];

void addObject(string object, int i, int j) {
  if (j==0) {
    matrice[i][j] = " "+object+" ";
  } 
  else if (j==9) {
    matrice[i][j] = " "+object+" \n";
  } else {
    matrice[i][j] = " "+object+" ";
  }
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
    cout << "\n";
  }
  cout <<"-----------------------------------------\n";
}

void initEnvironnement(int row, int col) {
  int i,j;

  for(i=0; i < row; i++)
  {
    for(j = 0; j < col; j++)
    {
      if (j==0) {
        matrice[i][j] = " ❎ ";
      } 
      else if (j==9) {
        matrice[i][j] = " ❎ \n";
      } else {
        matrice[i][j] = " ❎ ";
      }
    }
  }
}
#include <time.h> 

int getRandInt(int a, int b){ 
  return rand()%(b-a)+a; 
}

void lauchGame ( int row, int col, int obs, int nour, double absphero) {
    initEnvironnement(row, col);

    for (int i=0; i<obs; i++) {
      addObject("🕳 ", getRandInt(0,row),getRandInt(0,col));
    }

    for (int i=0; i<nour; i++) {
      addObject("🥗", getRandInt(0,row),getRandInt(0,col));
    }

    for (int i=0; i<10; i++) {
      addObject("🐜", getRandInt(0,row),getRandInt(0,col));
    }

    addObject("🏔 ", getRandInt(0,row),getRandInt(0,col));

    addObject("👑", getRandInt(0,row),getRandInt(0,col));


    afficherEnvironnement(row, col);
}

void updateGame(int row, int col, int i) {
  /* code */
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

  std::vector< std::vector<Cellule> > *vc;
  for (size_t i = 0; i < row; i++)
  {
    for (size_t j = 0; i < col; i++)
    {
      /* code */
      vc[i][j].push_back(Cellule());
    }
  }

  //Moteur moteur = new Moteur(vf,vn,vc,vo,popMax,nourMax);
  lauchGame(row,col,10,5,0.95);
  for (size_t i = 0; i < 15; i++)
  {
    
    updateGame(row,col,i);
    usleep(999999);
    system("clear");
  }

}