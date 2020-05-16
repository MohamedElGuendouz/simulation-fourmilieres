#include <iostream>
#include "fourmi.h"

/**
 * op= 
 */
fourmi::~fourmi()
{
  // liberation du positionleau de coord
  std::cout << "destructeur" ;
  //if (abs) delete abs ;
  //if (ord) delete ord ;
}

/**
 * op= 
 */
fourmi& fourmi::operator=(const fourmi& u)
{
  // liberation du positionleau de coord
    //if (abs) delete abs ;
    //if (ord) delete ord ;

  // initialisation du positionleau de coordonnées
    abs = u.abs ;
    ord = u.ord ; 

    return (*this) ;
}

