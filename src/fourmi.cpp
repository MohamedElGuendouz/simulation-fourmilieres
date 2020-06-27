#include <iostream>
#include "fourmi.h"

/**
 * op= 
 */
Fourmi& Fourmi::operator=(Fourmi const& u)
{
<<<<<<< HEAD
=======
  // liberation du positionleau de coord
  std::cout << "destructeur" ;
  //if (abs) delete abs ;
  //if (ord) delete ord ;
}

/**
 * op= 
 */
fourmi& fourmi::operator=(fourmi const& u)
{
  // liberation du positionleau de coord
    //if (abs) delete abs ;
    //if (ord) delete ord ;

>>>>>>> master
  // initialisation du positionleau de coordonnées
  this->x = u.x ;
  this->y = u.y ; 

  return (*this) ;
}

void Fourmi::setCoord(int x, int y){
  this->x = x;
  this->y = y;
}

void Fourmi::setCoord(double x, double y){
  
  this->x = int(x);
  this->y = int(y);
}