#pragma once

#include <iostream>
#include "ListaSekv.h"
#include "Ivica.h"
#include "set"
#include"MatricaSusjedstva.h"
using namespace std;

class DijkstraAlgoritam {

	MatricaSusjedstva* M;

	int* dist;
	int* pred;
	bool* posjecen;

	int startVrh;
	int endVrh;

	DijkstraAlgoritam(MatricaSusjedstva* M, int startVrh, int endVrh) {
		this->M = M;
		this->startVrh = startVrh;
		this->endVrh = endVrh;
		this->dist = new int[M->velicina];
		this->pred= new int[M->velicina];
		this->posjecen = new bool[M->velicina];
	}
	
	int minNeposjecenVrh(){
		int minDist = INT_MAX;
		int minVrh = -1;
		for (int i = 0; i < M->velicina; i++){
			if (!posjecen[i] && dist[i] < minDist) {
				minDist = dist[i];
				minVrh = i;
			}
		}
		return minVrh;
	}

	ListaSekv<Ivica*>* _start() {
		ListaSekv<Ivica*>* rezultat = new ListaSekv<Ivica*>;

		for (int i = 0; i < M->velicina; i++){
			dist[i] = INT_MAX;
			posjecen[i] = false;
		}

		dist[startVrh] = 0;

		for (int i = 0; i < M->velicina; i++){
			int nVrh= minNeposjecenVrh();
			posjecen[nVrh] = true;

			int nDist = dist[nVrh];
			for (int sVrh = 0; sVrh < M->velicina; sVrh++){
				if (M->isSusjed(nVrh, sVrh)) {
					int nsTezina = M->tezina(nVrh, sVrh);

					int xDist = nDist + nsTezina;

					if (xDist < dist[sVrh]) {
						dist[sVrh] = xDist;
						pred[sVrh] = nVrh;
					}
				}
			}
		}
		int ukupniPut = 0;

		int e = endVrh;
		while (e!=startVrh){
			int p = pred[e];
			int tezina = M->tezina(p, e);
			rezultat->dodaj(new Ivica(p, e, tezina));
			ukupniPut += tezina;
			e = p;
		}
		return rezultat;
	}
public:
	static Lista<Ivica*>* start(MatricaSusjedstva* M, int startVrh, int endVrh) {
		return DijkstraAlgoritam(M, startVrh, endVrh)._start;
	}

};
