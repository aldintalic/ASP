#pragma once

#include <iostream>

#include "ListaPov.h"
#include "MatricaSusjedstva.h"
#include "Ivica.h"
using namespace std;



class PrimAlgoritam{
	int startVrh;
	MatricaSusjedstva* M;
	Lista<int>* stabloVrhovi;
	Lista<Ivica*>* stabloIvice;

	PrimAlgoritam(MatricaSusjedstva* M, int startVrh){
		this->M = M;
		this->startVrh = startVrh;
		this->stabloIvice = new ListaPov<Ivica*>;
		this->stabloVrhovi = new ListaPov<int>;
	}


	Ivica* pripremiIvicu(){
		Ivica* ivica = new Ivica;
		ivica->tezina = INT_MAX;


		for (int fIndex = 0; fIndex < stabloVrhovi->count(); fIndex++){
			int fVrh = stabloVrhovi->get(fIndex);

			ListaSekv<int>* susjediLista = M->susjediTo(fVrh);

			int minSTezina = INT_MAX;
			int minSVrh = -1;

			for (int sIndex = 0; sIndex < susjediLista->count(); sIndex++){
				int sVrh = susjediLista->get(sIndex);
				if (stabloVrhovi->sadrzi(sVrh))
					continue;

				int tezina = M->tezina(fVrh, sVrh);

				if (tezina < minSTezina){
					minSTezina = tezina;
					minSVrh = sVrh;
				}
			}
			if (minSTezina < ivica->tezina){
				ivica->tezina = minSTezina;
				ivica->startVrh = fVrh;
				ivica->endVrh = minSVrh;
			}

		}

		return ivica;
	}

	Lista<Ivica*>* _start(){
		//PRIM počinje od proizvoljnog vrha, npr. prvi vrh
		stabloVrhovi->dodaj(startVrh);

		int s = 0;
		for (int brojac = 0; brojac < M->velicina - 1; brojac++){
			Ivica* i = pripremiIvicu();
			stabloIvice->dodaj(i);

			//s obzirom što se početak ivice uvjek nalazi u stablu-u onda je potrebno dodati samo kraj ivice.
			stabloVrhovi->dodaj(i->endVrh);
			s += i->tezina;
		}
		cout << "Prim Algoritam: MST suma je " << s << endl;
		return stabloIvice;
	}
public:
	static Lista<Ivica*>* start(MatricaSusjedstva* M, int startVrh = 0){
		return PrimAlgoritam(M, startVrh)._start();
	}
};
