#pragma once

#include"PrioritetniRed.h"

template <typename Tip>
class PrioritetniRedPov:public PrioritetniRed<Tip> {
	Cvor<Tip>* prvi = nullptr;
public:

	virtual void add(Tip v) {
		Cvor<Tip>* temp = prvi;
		Cvor<Tip>* p = nullptr;
		while(temp!=nullptr){
			if (v > temp->info)
				break;
			p = temp;
			temp = temp->next;
		}
		Cvor<Tip>* novi = new Cvor<Tip>(v, temp);

		if (p == nullptr)
			prvi = novi;
		else
			p->next = novi;
	}

	virtual Tip ukloni() {
		Cvor<Tip>* temp = prvi;
		prvi = prvi->next;
		Tip x = temp->info;
		delete temp;
		return x;
	
	}

	virtual bool isPrazan() { return prvi == nullptr; }

	virtual void print(string pre = "", string post = ", ") {
		Cvor<Tip>* temp = prvi;
		while (temp!=nullptr){
			cout << pre << temp->info << post;
			temp = temp->next;
		}
	}
};
