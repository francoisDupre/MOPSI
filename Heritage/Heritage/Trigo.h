#pragma once
#ifndef TRIGO_H
#define TRIGO_H

#include "Fonction.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Trigo : public Fonction
{
public:
	Trigo(string func, bool neg=false);

	float operator()(float x) const;
	Fonction* derivee() const;
	float inverse(float y);

private:
	string _func;
	bool _neg;
};

#endif