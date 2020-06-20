#include <cstddef>

class Fourmi {
    private:
        int abs;
        int ord;
    protected:
        int nourriture_max;
        int nourriture;
        int consommation;
        bool chercheNourriture;
    public:
        Fourmi(int x, int y):abs(x),ord(y),nourriture_max(30),nourriture(0),consommation(1),chercheNourriture(false){}
        Fourmi(const Fourmi& u):abs(u.abs),ord(u.ord){}
        //~Fourmi() ;
        Fourmi& operator=(Fourmi const&) ;

        //permet de déterminer comment se déplace la fourmi (<0 pas de deplacement ;
        // >=0 pourcentage flat sur un choix totalement aleatoire de case adjacente le reste
        // étant dédié à la partie aleatoire sur pheromone
        virtual int getParamDeplacement() const {return -1;};

        virtual bool getChercheNourriture() const {return chercheNourriture;};

        void setCoord(int x, int y);
        void setCoord(double x, double y);
        int getAbs() const { return abs; }
        void setAbs(int i) { abs = i ; }

        int getOrd() const { return ord; }
        void setOrd(int i) { ord = i ; }
};