
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "ListaPov.h"
#include "ListaSekv.h"
#include "Ivica.h"
using namespace std;


class MatricaSusjedstva{
	int** data;
public:
	const int velicina;

	MatricaSusjedstva(int v) : velicina(v) {
		data = new int*[velicina];
		for (int i = 0; i < velicina; i++)
			data[i] = new int[velicina] {0};
	}

	void ucitajMatricu(string filename) {
		ifstream ucitaj(filename);

		for (int i = 0; i < velicina; i++){
			for (int j = 0; j < velicina; j++){
				int x;
				ucitaj >> x;
				data[i][j] = x;
			}

		}
		ucitaj.close();
	}

	void ispisMatrice() {
		for (int i = 0; i < velicina; i++) {
			for (int j = 0; j < velicina; j++) {
				cout << data[i][j]<<"\t";
			}
			cout << endl;
		}
	}

	bool provjera() {
		for (int i = 0; i < velicina; i++){
			if (data[i][i] != 0)
				return false;
		}
		return true;
	}

	int izlazniStepen(int i) {
		int stepen = 0;
		for (int j = 0; j < velicina; j++)
			stepen += data[i][j];
		return stepen;
	}

	int ulazniStepen(int j) {	
		int stepen = 0;
		for (int i = 0; i < velicina; i++)
			stepen += data[i][j];
		return stepen;
	}


	ListaSekv<int>* susjediTo(int i) {
		ListaSekv<int>* susjedi = new ListaSekv<int>;

		for (int j = 0; j < velicina; j++)
			if (data[i][j] != 0)
				susjedi->dodaj(j);
		return susjedi;
	}

	ListaSekv<int>* susjediFrom(int j) {
		ListaSekv<int>* susjedi = new ListaSekv<int>;

		for (int i = 0; i < velicina; i++)
			if (data[i][j] != 0)
				susjedi->dodaj(j);
		return susjedi;
	}

	ListaPov<int>* izlazniStepenMax() {
		int* stepeni = new int[velicina];
		for (int i = 0; i < velicina; i++)
			stepeni[i] = izlazniStepen(i);

		int maxV = stepeni[0];
		for (int i = 1; i < velicina; i++)
			if (stepeni[i] > maxV) 
				maxV = stepeni[i];

		ListaPov<int>* maxStepeni = new ListaPov<int>;
		for (int i = 0; i < velicina; i++)
			if (stepeni[i] == maxV)
				maxStepeni->dodaj(i);

		return maxStepeni;
	}

	int tezina(int from, int to) { return data[from][to]; }

	int najbliziSusjed(int f) {
		ListaSekv<int>* susjedi_to = susjediTo(f);

		int minS = -1;
		int minT = INT_MAX;

		for (int i = 0; i < susjedi_to->count(); i++){
			int s = susjedi_to->get(i);
			int t = tezina(f, s);
			if (t < minT) {
				minT = t;
				minS = s;
			}
		}
		return minS;
	
	}

	void dodaj(Ivica * ivica) { data[ivica->startVrh][ivica->endVrh] = ivica->tezina; }

	bool isSusjed(int from, int to) { return data[from][to] != 0; }


};
