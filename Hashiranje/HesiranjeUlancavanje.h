#pragma once

#include"Hashiranje.h"
#include"ListaPov.h"

template <class Tip>
class HashiranjeUlancavanje:public Hashiranje<Tip>{
	ListaPov<Tip>* Niz;
	int n;
	int IzracunajHesh(int k) { return k % n; }
public:
	HashiranjeUlancavanje(int n){
		this->n = n;
		Niz = new ListaPov<Tip>[n];
	}

	virtual void dodaj(Tip k) {
		int key = IzracunajHesh(k);
		Niz[key].dodaj(k);
	}

	virtual bool ukloni(Tip k) {
		int key = IzracunajHesh(k);
		return Niz[key].Ukloni(k);
	}

	virtual void print() {
		for (int i = 0; i < n; i++){
			if (!Niz[i].isPrazan()) {
				cout << i << ": "; Niz[i].print();
			}
			else
				cout << i << ": X" << endl;

		}
	}
};
