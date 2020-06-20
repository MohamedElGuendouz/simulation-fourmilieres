#include "entite.h"

class nourriture: public Entite {

	private:
		int valeur;
	
	public: 
		int getvalue(){return valeur;}
};