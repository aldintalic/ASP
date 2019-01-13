#pragma once
#include<exception>
#include"Hashiranje.h"
#include<algorithm>

template<class Tip>
class HesiranjeOtvorenoAdresiranje :public Hashiranje<Tip> {
	Tip* Niz;
	int n;
	bool* zauzeto;
	int brojac;
	bool dvostruko;
	int IzracunajHash(Tip k) { return k % n; }
public:
	HesiranjeOtvorenoAdresiranje(int n=10,bool dvostruko=false){
		this->n = n;
		Niz = new Tip[n];
		zauzeto = new bool[n] {false};
		brojac = 0;
		this->dvostruko = dvostruko;
	}

	virtual void dodaj(Tip k) {
		if (isPun())
			throw exception("Greska. Tabela je puna.");
		int key = IzracunajHash(k);
		int pomak = 1;
		if (dvostruko)
			pomak = max(1, k / n);

		while (zauzeto[key]){
			key+=pomak;
			key %= n;
		}
		Niz[key] = k;
		zauzeto[key] = true;
		brojac++;
	}
	
	virtual bool ukloni(Tip k) {
		if (isPrazan())
			throw exception("Greska. Tabela je prazna.");
		int key = IzracunajHash(k);
		int p = 0;
		int pomak = 1;
		if (dvostruko)
			pomak = max(1, k / n);
		while (p!=n){
			if (zauzeto[key] && Niz[key] == k) {
				zauzeto[key] = false;
				cout << "Uklonjeno " << Niz[key] << endl;
				brojac--;
				return true;
			}
			key+=pomak;
			key %= n;
			p++;
		}
		return false;

	}
	
	virtual void print() {
		for (int i = 0; i < n; i++){
			if (zauzeto[i])
				cout << i << ":"<< Niz[i] << endl;
			else
				cout << i << ": X" << endl;
		}
	
	}
	
	bool isPun() { return brojac == n; }
	
	bool isPrazan() { return brojac == 0; }

};
