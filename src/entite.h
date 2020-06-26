#ifndef ENTITE_H
#define ENTITE_H

class Entite{
    protected:
        int x;
        int y;
    public:
        Entite():x(0),y(0){}
        Entite(int xv, int yv):x(xv),y(yv){}
        virtual void deplace(int x, int y){

        }
};
#endif 