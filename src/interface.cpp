#include <iostream>
#include "src/fourmiliere.h"
#include "src/fourmiliereSingleton.h"
using namespace std;

string matrice[5][10];

void addObject(string object, int i, int j) {
  if (j==0) {
    matrice[i][j] = "| "+object+" ";
  } 
  else if (j==9) {
    matrice[i][j] = " "+object+" |\n";
  } else {
    matrice[i][j] = " "+object+" ";
  }
}
string getObject(int i, int j) {
  return matrice[i][j];
}
void afficherEnvironnement(int row, int col) {
  int i,j;

  cout << "--------------------------------\n";
  for(i=0; i < row; i++)
  {
    for(j = 0; j < col; j++)
    {
      cout << matrice[i][j];
    }
  }
  cout <<"--------------------------------\n";
}

void initEnvironnement(int row, int col) {
  int i,j;

  for(i=0; i < row; i++)
  {
    for(j = 0; j < col; j++)
    {
      if (j==0) {
        matrice[i][j] = "| ■ ";
      } 
      else if (j==9) {
        matrice[i][j] = " ■ |\n";
      } else {
        matrice[i][j] = " ■ ";
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
      addObject("🕳", getRandInt(0,row),getRandInt(0,col));
    }

    for (int i=0; i<nour; i++) {
      addObject("🍔", getRandInt(0,row),getRandInt(0,col));
    }

    for (int i=0; i<10; i++) {
      addObject("🐜", getRandInt(0,row),getRandInt(0,col));
    }

    addObject("🏔", getRandInt(0,row),getRandInt(0,col));

    addObject("👑", getRandInt(0,row),getRandInt(0,col));


    afficherEnvironnement(row, col);
}
int main () {
  int row, col;
  row = 5;
  col = 10;

  lauchGame(row,col,10,5,0.95);
}