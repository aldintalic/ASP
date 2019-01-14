#pragma once

#include "BinarnoStablo.h"
#include "ListaPov.h"
#include "StekPov.h"
#include"RedPov.h"
template <class Tip>
class BSObilazak {

	static void rekurzija_PostOrder(BSCvor<Tip>* &cvor, Lista<Tip>* lista) {
		if (cvor != nullptr) {
			rekurzija_PostOrder(cvor->lijevoDijete, lista);
			rekurzija_PostOrder(cvor->desnoDijete, lista);
			lista->dodaj(cvor->value);
		}
	}

	static void rekurzija_InOrder(BSCvor<Tip>* &cvor, Lista<Tip>* lista) {
		if (cvor != nullptr) {
			rekurzija_InOrder(cvor->lijevoDijete, lista);
			lista->dodaj(cvor->value);
			rekurzija_InOrder(cvor->desnoDijete, lista);
		}
	}

	static void rekurzija_PreOrder(BSCvor<Tip>* &cvor, Lista<Tip>* lista) {
		if (cvor != nullptr) {
			lista->dodaj(cvor->value);
			rekurzija_PreOrder(cvor->lijevoDijete, lista);
			rekurzija_PreOrder(cvor->desnoDijete, lista);
		}
	}

public:

	static Lista<Tip>* PostOrder_R(BinarnoStabloZaPretrazivanje<Tip> &stablo) {
		Lista<Tip>* lista = new ListaPov <Tip>;
		rekurzija_PostOrder(stablo.korijen, lista);
		return lista;
	}

	static Lista<Tip>* PreOrder_R(BinarnoStabloZaPretrazivanje<Tip> &stablo) {
		Lista<Tip>* lista = new ListaPov <Tip>;
		rekurzija_PreOrder(stablo.korijen, lista);
		return lista;
	}

	static Lista<Tip>*  InOrder_R(BinarnoStabloZaPretrazivanje<Tip> &stablo) {
		Lista<Tip>* lista = new ListaPov<Tip>;
		rekurzija_InOrder(stablo.korijen, lista);
		return lista;
	}

	static Lista<Tip>* PreOrder_I(BinarnoStabloZaPretrazivanje<Tip> &stablo) {

		Lista<Tip>* lista = new ListaPov<Tip>;
		StekPov<BSCvor<Tip>*> stek;

		stek.dodaj(stablo.korijen);

		while (!stek.isPrazan()) {
			BSCvor<Tip>* x = stek.ukloni();

			lista->dodaj(x->value);
			if (x->desnoDijete != nullptr)
				stek.dodaj(x->desnoDijete);

			if (x->lijevoDijete != nullptr)
				stek.dodaj(x->lijevoDijete);
		}
		return lista;
	}

	static Lista<Tip>* NivoPoNivo_I(BinarnoStabloZaPretrazivanje<Tip> &stablo) {

		Lista<Tip>* lista = new ListaPov<Tip>;

		RedPov<BSCvor<Tip>*> red;
		red.dodaj(stablo.korijen);

		while (!red.isPrazan()){
			BSCvor<Tip>* cvor = red.ukloni();

			lista->dodaj(cvor->value);

			if (cvor->lijevoDijete != nullptr)
				red.dodaj(cvor->lijevoDijete);

			if (cvor->desnoDijete != nullptr)
				red.dodaj(cvor->desnoDijete);
		}

		return lista;
	}

	static Lista<Tip>* InOrder_I(BinarnoStabloZaPretrazivanje<Tip> &stablo) {
		Lista<Tip>* lista = new ListaPov<Tip>;

		BSCvor<Tip>* current = stablo.korijen;

		StekPov<BSCvor<Tip>*> stek;

		while (true) {
			if (current != nullptr) {
				stek.dodaj(current);
				current = current->lijevoDijete;
			}
			else {
				if (stek.isPrazan())
					break;
				current = stek.ukloni();
				lista->dodaj(current->value);
				current = current->desnoDijete;
			}
		}
		return lista;
	}

	static Lista<Tip>* PostOrder_I(BinarnoStabloZaPretrazivanje<Tip> &stablo) {
		Lista<Tip>* lista = new ListaPov<Tip>;
		Stek<Tip>* rezultat = new StekPov<Tip>;

		StekPov<BSCvor<Tip>*> stek;
		stek.dodaj(stablo.korijen);
		while (!stek.isPrazan()) {
			BSCvor<Tip>* cvor = stek.ukloni();
			if (cvor != nullptr) {
				rezultat->dodaj(cvor->value);
				stek.dodaj(cvor->lijevoDijete);
				stek.dodaj(cvor->desnoDijete);
			}

		}
		while (!rezultat->isPrazan()) {
			lista->dodaj(rezultat->ukloni());
		}
		return lista;
	}

};
