#pragma once

#include "Cvor.h"

template <typename Tip>
class PrioritetniRed{

public:

	virtual void add(Tip v) = 0;

	virtual Tip ukloni() = 0;

	virtual bool isPrazan() = 0;

	virtual void print(string pre = "", string post = ", ") = 0;
};
