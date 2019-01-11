#pragma once

#include"Lista.h"

template <class Tip>
class ListaSekv : public Lista<Tip>{
	Tip* N;
	int brojac;
	int max;
	void ProsiriListu() {
		max *= 2;
		Tip *temp = new Tip[max];
		for (int i = 0; i < brojac; i++)
			temp[i] = N[i];
		delete[] N;
		N = temp;
	}
public:
	ListaSekv(int max=10){
		this->max = max;
		N = new Tip[max];
		brojac = 0;
	}

	void dodaj(Tip v) {
		if (brojac == max)
			ProsiriListu();
		N[brojac++] = v;
	}

	Tip ukloni() {
		if (isPrazan())
			throw exception("Greska. Lista je prazna.");
		Tip x = N[--brojac];
		return x;
	}

	bool isPrazan() { return brojac == 0; }

	Tip& operator[](int i) { return get(i); }

	Tip& get(int i) {
		if (i < 0 || i >= brojac)
			throw exception("Greska. Nepostojeca lokacija.");
		return N[i];
	}

	void set(int i, Tip v) { get(i) = v; }

	void print(string pre = "", string post = ", ") {
		for (int i = 0; i < brojac; i++)
			cout << pre << N[i] << post;
		cout << endl;
	}

	int count() { return brojac; }

	bool sadrzi(Tip v) {
		for (int i = 0; i < brojac; i++)
			if (N[i] == v)
				return true;
		return false;
	}

	Tip* formirajNiz() {
		Tip* noviNiz = new Tip[this->brojac];
		for (int i = 0; i < this->brojac; i++)
			noviNiz[i] = this->N[i];
		return noviNiz;
	}
};
