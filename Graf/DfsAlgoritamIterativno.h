#pragma once


#include <iostream>

#include "ListaPov.h"
#include "PrioritetniRedPov.h"
#include "Ivica.h"
#include"MatricaSusjedstva.h"
#include"BfsAlgoritamIterativno.h"
using namespace std;

class KruskalAlgoritam
{
private:
	KruskalAlgoritam(MatricaSusjedstva* M){
		//ulazna matrica susjedstva
		grafMatrica = M;

		//PR koji ?uva sortirane ivice koje su formirane na osnovu ulazne matrice susjedstva 
		grafIvice = new PrioritetniRedPov<Ivica*>;

		//ovo je rezultat algoritma (stablo minimalnog raspona, MST)
		stabloIvice = new ListaPov<Ivica*>;

		//pomo?na matrica susjedstva za stablo (MST) koja se koristi radi Dfs i Bfs algoritma kod provjere ciklusa	
		stabloMatrica = new MatricaSusjedstva(M->velicina);
	}

	MatricaSusjedstva* grafMatrica;
	PrioritetniRed<Ivica*>* grafIvice;
	MatricaSusjedstva* stabloMatrica;
	Lista<Ivica*>* stabloIvice;

	void pripremiIvice(){
		for (int fromVrh = 0; fromVrh < grafMatrica->velicina; fromVrh++){
			Lista<int>* susjedi = grafMatrica->susjediTo(fromVrh);
			for (int toIndex = 0; toIndex < susjedi->count(); toIndex++){
				int toVrh = susjedi->get(toIndex);
				int tezina = grafMatrica->tezina(fromVrh, toVrh);
				Ivica* ivica = new Ivica(fromVrh, toVrh, tezina);
				grafIvice->add(ivica);
			}
		}
	}

	bool isCiklus(Ivica* i){
		Lista<int>* lista = BfsAlgoritamIterativno::start(stabloMatrica, i->endVrh);
		return lista->sadrzi(i->startVrh);
	}

	Lista<Ivica*>* _start(){
		pripremiIvice();

		int brojac = 0;
		int s = 0;

		while (brojac < (stabloMatrica->velicina) - 1){
			Ivica* i = grafIvice->ukloni();

			if (!isCiklus(i)){
				stabloIvice->dodaj(i);
				stabloMatrica->dodaj(i);
				s += i->tezina;
				brojac++;
			}
		}
		cout << "Kruskal Algoritam: MST suma je " << s << endl;

		return stabloIvice;
	}

public:

	static Lista<Ivica*>* start(MatricaSusjedstva* M){
		return KruskalAlgoritam(M)._start();
	}
};
