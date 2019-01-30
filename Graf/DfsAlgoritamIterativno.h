#pragma once

#include <iostream>

#include "StekSekv.h"
#include "ListaPov.h"
#include "ListaSekv.h"
using namespace std;

class DfsAlgoritamIterativno
{
private:
	int startVrh;
	MatricaSusjedstva* M;

	DfsAlgoritamIterativno(MatricaSusjedstva* M, int startVrh){
		this->startVrh = startVrh;
		this->M = M;
	}

	Lista<int>* _start(){
		Lista<int>* posjeceni = new ListaSekv<int>;

		StekSekv<int> stek;
		stek.dodaj(startVrh);

		while (!stek.isPrazan()){

			int v = stek.ukloni();

			if (!posjeceni->sadrzi(v)) {

				posjeceni->dodaj(v);

				for (int i = M->velicina; i >= 0; i--) {
					if (M->isSusjed(v, i)){
						if (!posjeceni->sadrzi(i))
							stek.dodaj(i);
					}
				}
			}
		}
		return posjeceni;
	}


public:
	static Lista<int>* start(MatricaSusjedstva* M, int startVrh = 0){
		return DfsAlgoritamIterativno(M, startVrh)._start();
	}
};
