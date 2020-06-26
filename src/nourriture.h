#include "entite.h"

class Nourriture: public Entite {

	private:
		int valeur;
	
	public: 
		int getValeur(){return valeur;};
		void setValeur(int v){valeur = v;};
};