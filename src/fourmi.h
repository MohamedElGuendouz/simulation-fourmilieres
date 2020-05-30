#include <cstddef>

class fourmi {
    private:
        int abs;
        int ord;
    public:
        fourmi(int x, int y):abs(x),ord(y){}
        fourmi(const fourmi& u):abs(u.abs),ord(u.ord){}
        ~fourmi() ;
        fourmi& operator=(fourmi const&) ;

        void setCoord(int x, int y);
        void setCoord(double x, double y);
        int getAbs() const { return abs; }
        void setAbs(int i) { abs = i ; }

        int getOrd() const { return ord; }
        void setOrd(int i) { ord = i ; }
};