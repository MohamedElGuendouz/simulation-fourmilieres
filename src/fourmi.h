#include <cstddef>

class Fourmi {
    private:
        int abs;
        int ord;
        int nourriture_max;
        int nourriture;
        int consommation;
    public:
        Fourmi(int x, int y):abs(x),ord(y){}
        Fourmi(const Fourmi& u):abs(u.abs),ord(u.ord){}
        //~Fourmi() ;
        Fourmi& operator=(Fourmi const&) ;

        void setCoord(int x, int y);
        void setCoord(double x, double y);
        int getAbs() const { return abs; }
        void setAbs(int i) { abs = i ; }

        int getOrd() const { return ord; }
        void setOrd(int i) { ord = i ; }
};