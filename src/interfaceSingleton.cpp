#include <iostream>
#include <stdlib.h>
#include "Moteur.h"
#include <typeinfo>
#include <time.h>
#include <unistd.h>

class Interface
{
private:
  std::string matrice[5][10];
  int fourmis;
  int reines;
  int nourritures;
  int obstacles;
  int fourmiliere;
  int popMax;
  int nourMax;
  int hauteur;
  int largeur;

  Interface(int fourmis, int reines, int nourritures, int obstacles, int fourmiliere, int popMax, int nourMax, int hauteur, int largeur)
  {
    this->nourritures = hauteur;
    this->obstacles = obstacles;
    this->fourmiliere = fourmiliere;
    this->popMax = popMax;
    this->nourMax = nourMax;
    this->fourmis = hauteur;
    this->reines = largeur;

    std::cout << fourmis << " " << reines << " " << nourritures << " " << obstacles << " " << fourmiliere << std::endl;

    Moteur moteur = Moteur(fourmis, reines, nourritures, obstacles, fourmiliere, popMax, nourMax, hauteur, largeur);

    lauchGame(hauteur, largeur);
    int partie = 15;

    for (int n = 0; n < 5; n++)
    {
      for (int m = 0; m < 10; m++)
      {
        std::cout << n << "  " << m << "   ";
        std::cout << moteur.containsFourmi(n, m);
        std::cout << moteur.containsObstacle(n, m);
        std::cout << moteur.containsNourriture(n, m);
        std::cout << moteur.containsFoumiliere(n, m);
        std::cout << moteur.containsReine(n, m);
        std::cout << std::endl;
      }
    }

    for (size_t i = 0; i < partie; i++)
    {
      if (i % 2 == 0)
      {
        std::cout << "[info] Partie en cours.\n"
                  << std::endl;
      }
      else
      {
        std::cout << "[info] Partie en cours...\n"
                  << std::endl;
      }
      updateGame(&moteur);
      moteur.next();

      if (i == 0)
      {
        std::cout << "[info] Debut de la partie\n"
                  << std::endl;
      }
      std::cout << "Partie : " << i << std::endl;

      usleep(999999);

      // Pour garder la dernière mise à jour
      if (i < partie - 1)
      {
        system("clear");
      }
      else
      {
        std::cout << "[info] Fin de la partie\n"
                  << std::endl;
      }
    }
  }

public:
  void afficherPositionEntite(Moteur *mot)
  {

    for (size_t i = 0; i < mot->getHauteur(); i++)
    {
      for (size_t j = 0; j < mot->getLargeur(); j++)
      {
        bool contentEntite = false;
        bool afficherEntite = false;

        if (mot->containsObstacle(i, j))
        {
          contentEntite = true;
          if (!afficherEntite)
          {
            std::cout << "[" << i << "]"
                      << "[" << j << "] : ";
            afficherEntite = true;
          }
          std::cout << " 🕳 ";
        }
        if (mot->containsFoumiliere(i, j))
        {
          contentEntite = true;
          if (!afficherEntite)
          {
            std::cout << "[" << i << "]"
                      << "[" << j << "] : ";
            afficherEntite = true;
          }
          std::cout << " 🏔 ";
        }
        if (mot->containsReine(i, j))
        {
          contentEntite = true;
          if (!afficherEntite)
          {
            std::cout << "[" << i << "]"
                      << "[" << j << "] : ";
            afficherEntite = true;
          }
          std::cout << " 👑 ";
        }
        else if (mot->containsFourmi(i, j))
        {
          contentEntite = true;
          if (!afficherEntite)
          {
            std::cout << "[" << i << "]"
                      << "[" << j << "] : ";
            afficherEntite = true;
          }
          std::cout << " 🐜 ";
        }
        if (mot->containsNourriture(i, j))
        {
          contentEntite = true;
          if (!afficherEntite)
          {
            std::cout << "[" << i << "]"
                      << "[" << j << "] : ";
            afficherEntite = true;
          }
          std::cout << " 🥗 ";
        }
        if (contentEntite)
        {
          std::cout << "\n";
          contentEntite = false;
        }
      }
    }
  }

  void addObject(std::string object, int i, int j)
  {

    int prioObject = 0;

    //std::cout << object;
    if (object == "🕳 ")
    {
      prioObject = 5;
    }
    else if (object == "🏔 ")
    {
      prioObject = 4;
    }
    else if (object == " 👑 ")
    {
      prioObject = 3;
    }
    else if (object == " 🐜 ")
    {
      prioObject = 2;
    }
    else if (object == " 🥗 ")
    {
      prioObject = 1;
    }
    //std::cout << matrice[i][j];

    int prioMaxCellule = 0;
    if (matrice[i][j] == " 🏔  ")
    {
      prioMaxCellule = 5;
    }
    else if (matrice[i][j] == " 🕳  ")
    {
      prioMaxCellule = 4;
    }
    else if (matrice[i][j] == " 👑 ")
    {
      prioMaxCellule = 3;
    }
    else if (matrice[i][j] == " 🐜 ")
    {
      prioMaxCellule = 2;
    }
    else if (matrice[i][j] == " 🥗 ")
    {
      prioMaxCellule = 1;
    }
    else if (matrice[i][j] == " ❎ ")
    {
      prioMaxCellule = 0;
    }
    //std::cout << prioObject << " " << prioMaxCellule;

    if (prioObject > prioMaxCellule)
    {
      if (prioObject >= 4)
        matrice[i][j] = " " + object + " ";
      else
      {
        matrice[i][j] = object;
      }
    }
    //std::cout << "  ======> [" << i << "," << j << "] = " << matrice[i][j] << "\n";
  }
  std::string getObject(int i, int j)
  {
    return matrice[i][j];
  }
  void afficherEnvironnement(int row, int col)
  {
    int i, j;

    std::cout << "\n"
              << "-----------------------------------------\n";
    std::cout << "\n";
    for (i = 0; i < row; i++)
    {
      for (j = 0; j < col; j++)
      {
        std::cout << matrice[i][j];
      }
      std::cout << "\n\n";
    }
    std::cout << "-----------------------------------------\n";
  }

  void initEnvironnement(int row, int col)
  {
    int i, j;

    for (i = 0; i < row; i++)
    {
      for (j = 0; j < col; j++)
      {
        if (j == 9)
        {
          matrice[i][j] = " ❎ ";
        }
        else
        {
          matrice[i][j] = " ❎ ";
        }
      }
    }
  }

  int getRandInt(int a, int b)
  {
    return rand() % (b - a) + a;
  }

  void lauchGame(int row, int col)
  {
    initEnvironnement(row, col);
  }
  /** Mettre à jour la matrice en fonction du terrain du moteur*/
  void updateMatrice(Moteur *mot)
  {

    initEnvironnement(mot->getHauteur(), mot->getLargeur());
    //std::cout << "x [i] = "<<terrain.size();
    for (size_t i = 0; i < mot->getHauteur(); i++)
    {
      //std::cout << "x [j] = "<<terrain[i].size();
      for (size_t j = 0; j < mot->getLargeur(); j++)
      {
        std::cout << "";
        if (mot->containsObstacle(i, j))
        {
          addObject("🕳 ", i, j);
        }
        if (mot->containsFoumiliere(i, j))
        {
          addObject("🏔 ", i, j);
        }
        if (mot->containsReine(i, j))
        {
          addObject(" 👑 ", i, j);
        }
        if (mot->containsFourmi(i, j))
        {
          addObject(" 🐜 ", i, j);
        }
        if (mot->containsNourriture(i, j))
        {
          addObject(" 🥗 ", i, j);
        }
      }
    }
  }
  void updateGame(Moteur *mot)
  {
    updateMatrice(mot);
    afficherPositionEntite(mot);
    afficherEnvironnement(mot->getHauteur(), mot->getLargeur());
  }
  static Interface& getInstance(int fourmis, int reines, int nourritures, int obstacles, int fourmiliere, int popMax, int nourMax, int hauteur, int largeur)
   {
      static Interface instance(fourmis, reines, nourritures, obstacles, fourmiliere, popMax, nourMax, hauteur, largeur);
      return instance;
   }
};

int main(int argc, char *argv[])
{
  srand(time(NULL));

  int row = 5;
  int col = 10;

  char *p;

  if (argc == 1)
  {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << " Menu      FOURMILIERE      PROJET LP73 " << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "1er parametre : nombre de partie" << std::endl;
    std::cout << "2eme parametre : nombre de fourmis" << std::endl;
    std::cout << "3eme parametre : nombre de reine" << std::endl;
    std::cout << "4eme parametre : nombre de nourriture" << std::endl;
    std::cout << "5eme parametre : nombre de populationMax" << std::endl;
    std::cout << "6eme parametre : nombre de nourritureMax" << std::endl;
    std::cout << "7eme parametre : nombre de obstacle" << std::endl;
    std::cout << "8eme parametre : nombre de fourmiliere" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
  }
  else
  {
    int partie = (int)(long)strtol(argv[1], &p, 10);
    int fourmis = (int)(long)strtol(argv[2], &p, 10);
    int reines = (int)(long)strtol(argv[3], &p, 10);
    int nourritures = (int)(long)strtol(argv[4], &p, 10);
    int populationMax = (int)(long)strtol(argv[5], &p, 10);
    int nourrituresMax = (int)(long)strtol(argv[6], &p, 10);
    int obstacles = (int)(long)strtol(argv[7], &p, 10);
    int fourmiliere = (int)(long)strtol(argv[8], &p, 10);

    std::cout << fourmis << " " << reines << " " << nourritures << " " << obstacles << " " << fourmiliere << std::endl;

    Interface::instance(fourmis, reines, nourritures, obstacles, fourmiliere, 15, 15, row, col);
  }
}