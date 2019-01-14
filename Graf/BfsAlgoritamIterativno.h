#pragma once

#include <iostream>

#include "RedPov.h"
#include "RedSekv.h"
#include "ListaPov.h"
#include "ListaSekv.h"
#include"MatricaSusjedstva.h"

using namespace std;

class BfsAlgoritamIterativno {
private:
	int starVrh;
	MatricaSusjedstva* M;

	BfsAlgoritamIterativno(MatricaSusjedstva* M, int startVrh) {
		this->M = M;
		this->starVrh = startVrh;
	}

	Lista<int>* _start() {
		this->M = M;
		Lista<int>* posjeceni = new ListaSekv<int>(M->velicina);

		RedPov<int> red;

		red.dodaj(starVrh);
		while (!red.isPrazan()){
			int v = red.ukloni();

			if (!posjeceni->sadrzi(v)) {
				posjeceni->dodaj(v);

				for (int i = 0; i < M->velicina; i++){
					
					if (M->isSusjed(v, i)) {
						if (!red.sadrzi(i) && !posjeceni->sadrzi(i))
							red.dodaj(i);
					}

				}
			}
		}
			return posjeceni;
	}


public:
	static Lista<int>* start(MatricaSusjedstva* M, int startVrh = 0){
		return BfsAlgoritamIterativno(M, startVrh)._start();
	}

};
