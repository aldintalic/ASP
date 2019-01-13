#pragma once

template <class Tip>
class Hashiranje
{
public:
	virtual void dodaj(Tip) = 0;
	virtual bool ukloni(Tip) = 0;
	virtual void print() = 0;
};
