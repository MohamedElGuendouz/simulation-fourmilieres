#include <cstddef>

class fourmi {
    private:
        int abs;
        int ord;
    public:
        fourmi(int x, int y):abs(x),ord(y){}
        fourmi::fourmi(const fourmi& u):abs(u.abs),ord(u.ord){}
        ~fourmi() ;
        fourmi& operator=(const fourmi&) ;

        int getCoordAbs() const { return abs; }
        void setCoordAbs(int i) { abs = i ; }

        int getCoordOrd() const { return ord; }
        void setCoordOrd(int i) { ord = i ; }
};