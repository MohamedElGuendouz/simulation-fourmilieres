#include <iostream>
#include "fourmi.h"

/**
 * op= 
 */
Fourmi& Fourmi::operator=(Fourmi const& u)
{
  // liberation du positionleau de coord
    //if (abs) delete abs ;
    //if (ord) delete ord ;

  // initialisation du positionleau de coordonnées
  abs = u.abs ;
  ord = u.ord ; 

  return (*this) ;
}

void Fourmi::setCoord(int abs, int ord){
  this->abs = abs;
  this->ord = ord;
}

void Fourmi::setCoord(double x, double y){
  
  this->abs = int(abs);
  this->ord = int(ord);
}