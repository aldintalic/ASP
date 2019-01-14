#pragma once


#include <iostream>
#include <string>

using namespace std;

struct Ivica {

	int startVrh;
	int endVrh;
	int tezina;

public:

	Ivica(int startVrh,int endVrh,int tezina){
		this->startVrh = startVrh;
		this->endVrh= endVrh;
		this->tezina = tezina;
	}

};
