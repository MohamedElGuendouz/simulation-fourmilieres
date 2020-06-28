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
  if(matrice[i][j] == " 🏔  "){
    prioMaxCellule=5;
  } else if(matrice[i][j] == " 🕳  "){
    prioMaxCellule=4;
  } else if(matrice[i][j] == " 👑 "){
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

  cout << "\n"<<"-----------------------------------------\n";
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
}
/** Mettre à jour la matrice en fonction du terrain du moteur*/
void updateMatrice(Moteur* mot) {

  initEnvironnement(mot->getHauteur(), mot->getLargeur());
  //cout << "x [i] = "<<terrain.size();
  for (size_t i = 0; i < mot->getHauteur(); i++)
  {
    //cout << "x [j] = "<<terrain[i].size();
    for (size_t j = 0; j < mot->getLargeur(); j++)
    {     
      cout << "";
      if (mot->containsObstacle(i,j)) {
        addObject("🕳 ", i,j);
      }
      if (mot->containsFoumiliere(i,j)) {
        addObject("🏔 ", i,j);
      }
      if (mot->containsReine(i,j)) {
        addObject(" 👑 ", i,j);
      }
      if (mot->containsFourmi(i,j)) {
        addObject(" 🐜 ", i,j);
      }
      if (mot->containsNourriture(i,j)) {
        addObject(" 🥗 ", i,j);
      }
    }
  }
}

void updateGame(Moteur* mot) {
  
  updateMatrice(mot);
  afficherEnvironnement(mot->getHauteur(),mot->getLargeur());
}


#include <unistd.h>

int main (int argc, char *argv[]) {

  srand(time(NULL));
  int row = 5;
  int col = 10;

  char* p;

  if(argc==1){
    cout << "----------------------------------------"<<endl;
    cout << " Menu      FOURMILIERE      PROJET LP73 "<<endl;
    cout << "----------------------------------------"<<endl;
    cout << "1er parametre : nombre de fourmis"<<endl;
    cout << "2eme parametre : nombre de reine"<<endl;
    cout << "3eme parametre : nombre de nourriture"<<endl;
    cout << "4eme parametre : nombre de obstacle"<<endl;
    cout << "5eme parametre : nombre de fourmiliere"<<endl;
    cout << "----------------------------------------"<<endl;

  }else {
    int fourmis=(int)(long)strtol(argv[1], &p, 10);
    int reines=(int)(long)strtol(argv[2], &p, 10);
    int nourritures=(int)(long)strtol(argv[3], &p, 10);
    int obstacles=(int)(long)strtol(argv[4], &p, 10);
    int fourmiliere=(int)(long)strtol(argv[5], &p, 10);

    cout << fourmis << " " <<  reines << " " << nourritures << " " <<  obstacles << " " <<  fourmiliere << std::endl;

    Moteur moteur = Moteur(fourmis,reines,nourritures,obstacles,fourmiliere,15,15,row,col);

    lauchGame(row,col);
    int partie = 15;

    /*for(int n=0;n<5;n++){
      for(int m=0;m<10;m++){
        cout<<n<<"  "<<m<< "   ";
        cout<<moteur.containsFourmi(n,m);
        cout<<moteur.containsObstacle(n,m);
        cout<<moteur.containsNourriture(n,m);
        cout<<moteur.containsFoumiliere(n,m);
        cout<<moteur.containsReine(n,m);
        cout<<endl;
      }
    }*/
    
    for (size_t i = 0; i < partie; i++)
    {
      if(i%2==0) {
        cout << "[info] Partie en cours.\n" << std::endl;
      } else {
        cout << "[info] Partie en cours...\n" << std::endl;
      }
      moteur.next();
      updateGame(&moteur);


      if(i==0){
        cout << "[info] Debut de la partie\n" << std::endl;
      }
      cout << "Partie : "<< i << std::endl;
      
      usleep(999999);

      // Pour garder la dernière mise à jour
      if(i<partie-1) {
        system("clear");
      }else {
        cout << "[info] Fin de la partie\n" << std::endl;
      }
    }
  }
}