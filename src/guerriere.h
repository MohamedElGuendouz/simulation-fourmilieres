#include "fourmi.h"

typedef enum { EXPLORATION , RETOUR } T_TYPE_DEPLACEMENT ;
//int DEPLACEMENT_EXPLORATION = 60; // 0 <= v <= 100
//int DEPLACEMENT_RETOUR = 0; // 0 <= v <= 100

class Guerriere : public Fourmi {
    private:
        T_TYPE_DEPLACEMENT deplacement;
    public:
        Guerriere(int x, int y);
        T_TYPE_DEPLACEMENT getTypeDeplacement();
        void setTypeDeplacement(T_TYPE_DEPLACEMENT t);

        int getParamDeplacement() const;
};