#pragma once

#include <iostream>
using namespace std;

template <class Tip>
struct Cvor {
	Cvor* next;
	Tip info;
	
	Cvor(Tip info,Cvor* next){
		this->info = info;
		this->next = next;
	}

};
