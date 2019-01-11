#pragma once

#include"Stek.h"

template <class Tip>
class StekSekv : public Stek<Tip> {
	int brojac;
	Tip* N;
	int max;
	void prosiriStek() {
		max *= 2;
		Tip* temp = new Tip[max];
		for (int i = 0; i < brojac; i++)
			temp[i] = N[i];
		delete[] N;
		N = temp;
	}

public:
	StekSekv(int max = 10) {
		brojac = 0;
		this->max = max;
		N = new Tip[max];
	}

	void dodaj(Tip v) {
		if (max == brojac)
			prosiriStek();
		N[brojac++] = v;
	}

	Tip ukloni() {
		if (isPrazan())
			throw exception("Greska. Stek je prazan.");
		Tip x = N[--brojac];
		return x;
	}

	Tip vrh() { 
		if (isPrazan())
			throw exception("Greska. Stek je prazan.");
		
		return N[brojac - 1]; 
	}

	bool isPrazan() {	return brojac == 0;}

	void print(string pre = "", string post = ", ") {
		for (int i = 0; i < brojac; i++)
			cout << pre << N[i] << post;
		cout << endl;
	}

	bool sadrzi(Tip v){
		for (int i = 0; i < brojac; i++)
			if (N[i] == v)
				return true;
		return false;
	}
};
