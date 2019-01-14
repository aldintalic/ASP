#pragma once

#include <iostream>
#include "BSCvor.h"
using namespace std;

template <class Tip>
class BinarnoStabloZaPretrazivanje {

	void rekurzija_ReciklirajStablo(BSCvor<Tip>*& cvor) {
		if (cvor != nullptr) {
			rekurzija_ReciklirajStablo(cvor->desnoDijete);
			rekurzija_ReciklirajStablo(cvor->lijevoDijete);
			delete cvor;
			cvor = nullptr;
		}
	}

	BSCvor<Tip>* rekurzija_Trazi(BSCvor<Tip>* cvor, Tip value) {
		if (cvor == nullptr)
			return nullptr;

		if (value == cvor->value)
			return cvor;

		if (value > cvor->value)
			return rekurzija_ReciklirajStablo(cvor->desnoDijete, value);
		else
			return rekurzija_ReciklirajStablo(cvor->lijevoDijete, value);
	}

	bool rekurzija_Dodaj(BSCvor<Tip>* &cvor, Tip value) {
		if (cvor == nullptr) {
			cvor = new BSCvor<Tip>(value);
			return true;
		}

		if (cvor->value == value)
			return false;

		if (value > cvor->value)
			return rekurzija_Dodaj(cvor->desnoDijete, value);
		else
			return rekurzija_Dodaj(cvor->lijevoDijete, value);
	}


public:
	BSCvor<Tip>* korijen;

	BinarnoStabloZaPretrazivanje() { korijen = nullptr; }

	bool dodaj(Tip value) {
		if (korijen == nullptr)
			korijen = new BSCvor<Tip>(value);
		return rekurzija_Dodaj(korijen, value);
	}

	void reciklirajStablo() { return rekurzija_ReciklirajStablo(korijen); }

	BSCvor<Tip>* trazi(Tip value) {
		return rekurzija_Trazi(korijen,value);
	}

	bool sadrzi(Tip value) {
		return trazi(value) != nullptr;
	}
};
