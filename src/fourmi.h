#include <cstddef>

typedef enum { LARVE , OEUF , FOURMI } T_ETAT_FOURMI ;
typedef enum { REINE , GUERRIERE , OUVRIERE } T_STATUS_FOURMI ;
typedef enum { EXPLORATION , RAVITAILLEMENT , AUFRONT } T_EXPLORATION_FOURMI ;

class Fourmi : public Entite {
    private:
        T_ETAT_FOURMI etat;
        T_STATUS_FOURMI status;
        T_EXPLORATION_FOURMI exploration;

        int abs;
        int ord;
        int lifeValue;
        int age;
        int consommation;
        int nourriture;
        int nourritureMax;

    public:
        Fourmi(int x, int y, T_ETAT_FOURMI etat,T_STATUS_FOURMI status):abs(x),ord(y),etat(etat),status(status){age = 0;}
        Fourmi(const Fourmi& u):abs(u.abs),ord(u.ord){}
        ~Fourmi() ;
        Fourmi& operator=(Fourmi const&) ;
        int getNourriture(){return nourriture;};
        int getNourritureMax(){return nourritureMax;};

        void setNourriture(int i){nourriture=i;};
        void setNourritureMax(int i){nourritureMax=i;};

        void setCoord(int x, int y);
        void setCoord(double x, double y);
        int getAbs() const { return abs; }
        void setAbs(int i) { abs = i ; }

        int getOrd() const { return ord; }
        void setOrd(int i) { ord = i ; }

        void downLifeValue(){lifeValue--;};
        int getLifeValue(){return lifeValue;};

        void upYear(){age++;};

        T_ETAT_FOURMI getEtat(){return etat;};
        void setEtat(T_ETAT_FOURMI r){this->etat=r;};

        T_STATUS_FOURMI getStatus(){return status;};
        void setStatus(T_STATUS_FOURMI s){this->status=s;};

        void changeEtat();
        void changeStatus();
        void changeExploration();

};