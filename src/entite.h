#ifndef ENTITE_H
#define ENTITE_H
#include <string>
#include <iostream>

class Entite{
    protected:
        int x;
        int y;
        int type;
    public:
        Entite():x(0),y(0){}
        Entite(int xv, int yv,int t):x(xv),y(yv),type(t){}
        virtual void deplace(int x, int y){}
        virtual int getType(){return this->type;};
        virtual void affichType(){std::cout<<this->type<<std::endl;}
};
#endif 