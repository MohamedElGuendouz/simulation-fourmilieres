#include "fourmi.h"

typedef enum { EXPLORATION , RETOUR } T_TYPE_DEPLACEMENT ;

class guerriere : Fourmi {
    private:
        T_TYPE_DEPLACEMENT deplacement;
    public:
        T_TYPE_DEPLACEMENT getTypeDeplacement();
        void setTypeDeplacement(T_TYPE_DEPLACEMENT t);
};