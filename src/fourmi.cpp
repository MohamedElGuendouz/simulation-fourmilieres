#include <iostream>
#include "fourmi.h"

/**
 * op= 
 */
Fourmi& Fourmi::operator=(Fourmi const& u)
{
  // initialisation du positionleau de coordonnées
  this->x = u.x ;
  this->y = u.y ; 

  return (*this) ;
}