#include <cstddef>
#include "entite.h"
typedef enum { LARVE , OEUF , FOURMI } T_ETAT_FOURMI ;
typedef enum { REINE , GUERRIERE , OUVRIERE } T_STATUS_FOURMI ;
typedef enum { EXPLORATION , RAVITAILLEMENT , AUFRONT } T_EXPLORATION_FOURMI ;

class Fourmi : public Entite {
    private:
        T_ETAT_FOURMI etat;
        T_STATUS_FOURMI status;
        T_EXPLORATION_FOURMI exploration;
        
        int lifeValue;
        int age;
        int consommation;
        int nourriture;
        int nourritureMax;

    public:
        Fourmi(int x, int y, T_ETAT_FOURMI etat,T_STATUS_FOURMI status):Entite(x,y,"fourmi"){age = 0;lifeValue=10;}
        Fourmi(const Fourmi& u):Entite(u.x,u.y,"fourmi"){}
        //~Fourmi() ;
        Fourmi& operator=(Fourmi const&) ;
        int getNourriture(){return nourriture;};
        int getNourritureMax(){return nourritureMax;};

        void setNourriture(int i){nourriture=i;};
        void setNourritureMax(int i){nourritureMax=i;};

        void setCoord(int x, int y);
        void setCoord(double x, double y);
        int getAbs() const { return this->x; }
        void setAbs(int i) { this->x = i ; }

        int getOrd() const { return this->y; }
        void setOrd(int i) { this->y = i ; }

        void downLifeValue(){lifeValue--;};
        int getLifeValue(){return lifeValue;};

        void upYear(){age++;};

        T_ETAT_FOURMI getEtat(){return etat;};
        void setEtat(T_ETAT_FOURMI r){this->etat=r;};

        T_EXPLORATION_FOURMI modeExploration(){return exploration;}

        T_STATUS_FOURMI getStatus(){return status;};
        void setStatus(T_STATUS_FOURMI s){this->status=s;};

        void changeEtat(){};
        void changeStatus(){};
        void changeExploration(){};

};