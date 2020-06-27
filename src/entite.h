#ifndef ENTITE_H
#define ENTITE_H
#include <string>

class Entite{
    protected:
        int x;
        int y;
        std::string type;
    public:
        Entite():x(0),y(0){}
        Entite(int xv, int yv,std::string t):x(xv),y(yv),type(t){}
        virtual void deplace(int x, int y){
        }
        std::string getType(){return this->type;};
};
#endif 