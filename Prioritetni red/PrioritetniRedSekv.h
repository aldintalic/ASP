#pragma once

#include"PrioritetniRed.h"

template<class Tip>
class PriroritetniRedSekv :public PrioritetniRed<Tip> {
	int vel = 13;
	Tip* N = new Tip[vel];
	int brojac = 0;
	void ProsiriRed() {
		Tip* temp = new Tip[vel * 2];
		for (int i = 0; i < brojac; i++)
			temp[i] = N[i];
		
		delete[] N;
		N = temp;
		vel *= 2;

	}
public:
	virtual void add(Tip v) {
		if (isPun())
			ProsiriRed();

		N[brojac++] = v;
	}

	virtual Tip ukloni(){
		if (isPrazan())
			throw exception("Greska. Red je prazan.");
		int maxI = 0, maxV = N[maxI];
		for (int i = 0; i < brojac; i++) {
			if (N[i] > N[maxI]) {
				maxI = i;
				maxV = N[i];
			}
		}
		Tip x = N[maxI];
		N[maxI] = N[--brojac];
		return x;
		
	}

	bool isPun() { return brojac == vel; }

	virtual bool isPrazan() { return brojac == 0; }

	virtual void print(string pre = "", string post = ", ") {
		for (int i = 0; i < brojac; i++)
			cout << pre << N[i] << post;
	
	}


};
