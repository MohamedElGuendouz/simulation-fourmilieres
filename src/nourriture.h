class Nourriture: public Entite {

	private:
		int valeur;
	
	public: 
		int getValeur(){return valeur;};
		int setValeur(int v){valeur = v;};
};