#include <iostream>
#include "src/fourmi.h"

int main() {
    fourmi f1(3,2);
    fourmi f2(0,2);

    f1.setCoord(0.1, 3.14) ;
    std::cout << "f1 abs" << f1.getAbs() << std::endl ;
    std::cout << "f1 ord" << f1.getOrd() << std::endl ;

    std::cout << "f2 abs" << f2.getAbs() << std::endl ;
    std::cout << "f2 ord" << f2.getOrd() << std::endl ;

    fourmi f3(f1);
    std::cout << "f1 abs" << f1.getAbs() << std::endl ;
    std::cout << "f1 ord" << f1.getOrd() << std::endl ;

    std::cout << "f2 abs" << f2.getAbs() << std::endl ;
    std::cout << "f2 ord" << f2.getOrd() << std::endl ;

    f2=f3;
    std::cout << "f1 abs" << f1.getAbs() << std::endl ;
    std::cout << "f1 ord" << f1.getOrd() << std::endl ;
    
    std::cout << "f2 abs" << f2.getAbs() << std::endl ;
    std::cout << "f2 ord" << f2.getOrd() << std::endl ;

    std::cout << "f3 abs" << f3.getAbs() << std::endl ;
    std::cout << "f3 ord" << f3.getOrd() << std::endl ;

    return 0;
}