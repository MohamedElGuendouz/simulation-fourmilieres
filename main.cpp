#include <iostream>
#include "src/fourmiliere.h"
#include "src/fourmiliereSingleton.h"
//#include "src/environnementSingleton.h"

void testSingleton() {
    /**std::cout << "Test de singleton pour un Environnement!\n";

    EnvironnementSingleton* env1 = EnvironnementSingleton::getInstance();
    EnvironnementSingleton* env2 = EnvironnementSingleton::getInstance();

    std::cout << env1 << std::endl;
    std::cout << env2 << std::endl;
*/
    std::cout << "---------------------\n";
    std::cout << "Test de singleton pour une Fourmiliere!\n";

    FourmiliereSingleton* four1 = FourmiliereSingleton::getInstance();
    FourmiliereSingleton* four2 = FourmiliereSingleton::getInstance();

    std::cout << four1 << std::endl;
    std::cout << four2 << std::endl;
}
int main() {
    std::cout << "Bienvenue!\n";

}