#pragma once

#include "Cvor.h"
#include"Red.h"

template <class Tip>
class RedPov:public Red<Tip> {
	Cvor<Tip>* pocetak;
	Cvor<Tip>* kraj;
public:
	RedPov():pocetak(nullptr),kraj(nullptr){}

	virtual void dodaj(Tip v) {
		Cvor<Tip>* novi = new Cvor<Tip>(v, nullptr);
		
		if (pocetak == nullptr)
			pocetak = novi;
		else
			kraj->next = novi;
		
		kraj = novi;
	}

	virtual Tip ukloni() {
		if (isPrazan())
			throw exception("Greska. Red je prazan.");
		
		Cvor<Tip>* temp = pocetak;
	
		pocetak = pocetak->next;

		Tip x = temp->info;
		delete temp;
		
		if (kraj == nullptr)
			kraj = nullptr;
		
		return x;
	
	}

	virtual bool isPrazan() { return pocetak == nullptr; }//ili kraj==nullptr 

	virtual void print(string pre = "", string post = ", ") {
		Cvor<Tip>* temp = pocetak;

		while (temp!=nullptr){
			cout << pre << temp->info << post;
			temp = temp->next;
		}

	}

	virtual bool sadrzi(Tip v) {
		Cvor<Tip>* temp = pocetak;

		while (temp != nullptr) {
			if (temp->info == v)
				return true;
			temp = temp->next;
		}
		return false;

	}
};
