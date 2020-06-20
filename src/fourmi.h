#include <cstddef>

typedef enum { LARVE , OEUF , FOURMI} T_ETAT_FOURMI ;
typedef enum { REINE , GUERRIERE , OUVRIERE } T_STATUS_FOURMI ;
typedef enum { EXPLORATION , RAVITAILLEMENT , AUFRONT } T_EXPLORATION_FOURMI ;

class fourmi : public Entite {
    private:
        T_ETAT_FOURMI etat;
        T_STATUS_FOURMI status;
        T_EXPLORATION_FOURMI exploration;

        int abs;
        int ord;
        int lifevalue;
        int age;
        int consommation;
    public:
        fourmi(int x, int y, T_ETAT_FOURMI etat,T_STATUS_FOURMI status):abs(x),ord(y),etat(etat),status(status){age = 0;}
        fourmi(const fourmi& u):abs(u.abs),ord(u.ord){}
        ~fourmi() ;
        fourmi& operator=(fourmi const&) ;

        void setCoord(int x, int y);
        void setCoord(double x, double y);
        int getAbs() const { return abs; }
        void setAbs(int i) { abs = i ; }

        int getOrd() const { return ord; }
        void setOrd(int i) { ord = i ; }

        void downlifevalue(){lifevalue--;};
        void getlifevalue(){return lifevalue;};

        void upyear(){age++;};

        T_TYPE_FOURMI getrole(){return role;};
        void setrole(T_TYPE_FOURMI r){this->role=r;};

        T_TYPE_FOURMI getrole(){return role;};
        setrole(T_TYPE_FOURMI r){this->role=r;};

};