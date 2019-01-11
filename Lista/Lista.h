#pragma once
#include <string>
using namespace std;

template <class Tip>
class Lista
{
public:
	virtual void dodaj(Tip v) = 0;

	virtual Tip ukloni() = 0;

	virtual bool isPrazan() = 0;

	virtual Tip& operator[](int i) = 0;

	virtual Tip& get(int i) = 0;

	virtual void set(int i, Tip v) = 0;

	virtual void print(string pre = "", string post = ", ") = 0;

	virtual int count() = 0;

	virtual bool sadrzi(Tip v) = 0;

	virtual Tip* formirajNiz() = 0;
};
