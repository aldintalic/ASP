#pragma once

template <class Tip>
struct BSCvor {

	Tip value;
	BSCvor* lijevoDijete;
	BSCvor* desnoDijete;
	
	BSCvor(Tip value){
		lijevoDijete = desnoDijete = nullptr;
		this->value = value;
	}


};
