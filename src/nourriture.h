#include "entite.h"

class Nourriture: public Entite {

	private:
		int valeur;
	
	public: 
		Nourriture(int xv, int yv, int v):Entite(xv,yv,"nourriture"){this->valeur=v;};
		int getValeur(){return this->valeur;};
		void setValeur(int v){this->valeur = v;};
};