#include <iostream>
#include "entite.h"

class FourmiliereSingleton
{
  private:
    /* Here will be the instance stored. */
    static FourmiliereSingleton* instance;
    /* Private constructor to prevent instancing. */
    FourmiliereSingleton();

    unsigned int populationMax;
    unsigned int nourritureMax;
    unsigned int nourriture;
    std::vector<Entite> contenu;
  public:
    /* Static access method. */
    static FourmiliereSingleton* getInstance();
    void ajoutNourriture(int n);
    bool consommeNourriture(int n);
};

  /* Null, because instance will be initialized on demand. */
  FourmiliereSingleton* FourmiliereSingleton::instance = 0;
  FourmiliereSingleton* FourmiliereSingleton::getInstance()
  {
  if (instance == 0)
      {
          instance = new FourmiliereSingleton();
      }
  return instance;
  }
  FourmiliereSingleton::FourmiliereSingleton()
  {}

void FourmiliereSingleton::ajoutNourriture(int n){
    if(nourriture + n >= nourritureMax) {
        nourriture = nourritureMax;
    } else {
        nourriture += n;
    }
}

bool FourmiliereSingleton::consommeNourriture(int n){
    if(nourriture - n < 0) {
        return false;
    } else {
        nourriture -= n;
        return true;
    }
}