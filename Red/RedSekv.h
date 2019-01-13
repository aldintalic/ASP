#pragma once

#include "Cvor.h"
#include"Red.h"
template <class Tip>
class RedSekv:public Red<Tip>{
	int pocetak;
	int kraj;
	Tip* niz;
	int max;
	int brojac;
	void ProsiriRed() {
		max *= 2;
		Tip* temp = new Tip[max];
		int j = pocetak;
		for (int i = 0; i < brojac; i++){
			temp[i] = niz[j++];
			pocetak %= max;
		}
		delete[] niz;
		niz = temp;
		pocetak = 0;
		kraj = brojac;


	}
public:
	RedSekv(int max):pocetak(0),kraj(0),brojac(0){
		this->max = max;
		niz = new Tip[max];
	}

	virtual void dodaj(Tip v) {
		if (IsPuna())
			ProsiriRed();

		niz[kraj++] = v;
		kraj %= max;
		brojac++;
	}

	virtual Tip ukloni() {
		if (isPrazan())
			throw exception("Greska. Red je prazan.");

		Tip x = niz[pocetak++];
		brojac--;
		pocetak %= max;
		return x;
	}

	virtual bool isPrazan() {return brojac == 0;}

	virtual void print(string pre = "", string post = ", ") {
		int j = pocetak;
		for (int i = 0; i < brojac; i++){
			cout << pre << niz[j] << post;
			j++;
			j %= max;
		}
	}

	virtual bool sadrzi(Tip v) {
		int j = pocetak;
		for (int i = 0; i < brojac; i++) {
			if (niz[j] == v)
				return true;
			j++;
			j %= max;
		}
		return false;

	}

	bool IsPuna() { return brojac == max; }
};
