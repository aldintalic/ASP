#pragma once

#include "Cvor.h"
#include "Stek.h"

template <class Tip>
class StekPov :public Stek<Tip>
{
	Cvor<Tip>* prvi;

public:
	StekPov() { prvi = nullptr; }

	void dodaj(Tip v) {
		Cvor<Tip>* novi = new Cvor<Tip>(v, prvi);
		prvi = novi;
	}

	Tip ukloni() {
		if (isPrazan())
			throw exception("Greska. Stek je prazan.");
		Cvor<Tip>* temp = prvi;
		prvi = prvi->next;
		Tip x = temp->info;
		delete temp;
		return x;
	}

	Tip vrh(){
		if (isPrazan())
			throw exception("Greska. Stek je prazan.");
		return prvi->info;
	}

	bool isPrazan() { return prvi == nullptr; }

	void print(string pre = "", string post = ", ") {
		Cvor<Tip>* temp = prvi;
		while (temp!=nullptr){
			cout << pre << temp->info << post;
			temp = temp->next;
		}
		cout << endl;
	}

	bool sadrzi(Tip v) {
		Cvor<Tip>* temp = prvi;
		while (temp != nullptr) {
			if (temp->info == v)
				return true;
			temp = temp->next;
		}
		return false;
	}

};
