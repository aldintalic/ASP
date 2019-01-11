#pragma once

#include "Lista.h"
#include "Cvor.h"

template <class Tip>
class ListaPov : public Lista<Tip>{
	int brojac;
	Cvor<Tip>* prvi;

public:
	ListaPov(){
		brojac = 0;
		prvi = nullptr;
	}

	void dodaj(Tip v) {
		Cvor<Tip>* novi = new Cvor<Tip>(v, prvi);
		prvi = novi;
		brojac++;
	}

	Tip ukloni() {
		if (isPrazan())
			throw exception("Greska. Lista je prazna.");
		
		Cvor<Tip>* temp = prvi;
		prvi = prvi->next;
		Tip x = temp->info;
		delete temp;
		brojac--;
		return x;
	}

	bool Ukloni(Tip v) {
		Cvor<Tip>* temp = prvi;
		Cvor<Tip>* p = nullptr;
		while (temp!=nullptr){
			if (temp->info == v)
				break;
			p = temp;
			temp = temp->next;
		}
		if (temp == nullptr)
			return false;
		
		if (p == nullptr)
			prvi = temp->next;
		else
			p->next = temp->next;
		
		delete temp;
		brojac--;
		return true;
	}

	bool isPrazan() { return prvi == nullptr; }

	Tip& operator[](int i) { return get(i); }

	Tip& get(int i) {
		if (i < 0 || i >= brojac)
			throw exception("Greska. Nepostojeca pozicija.");
		Cvor<Tip>* temp = prvi;		      
		for (int j = 0; j < i+1; j++)   
			temp = temp->next;		
		return temp->info;
	}

	void set(int i, Tip v) { get(i) = v; }

	void print(string pre = "", string post = ", ") {
		Cvor<Tip>* temp = prvi;
		while (temp!=nullptr){
			cout << pre << temp->info << post;
			temp = temp->next;
		}
		cout << endl;
	}

	int count() {return brojac;}

	bool sadrzi(Tip v) {
		Cvor<Tip>* temp = prvi;
		while (temp != nullptr) {
			if (temp->info == v)
				return true;
			temp = temp->next;
		}
		return false;
	}

	Tip* formirajNiz() {
		Tip* noviNiz = new Tip[this->brojac];
		Cvor<Tip>* temp = prvi;
		int b = 0;
		while (temp!=nullptr){
			noviNiz[b++] = temp->info;
			temp = temp->next;
		}
		return noviNiz;
	}

};
