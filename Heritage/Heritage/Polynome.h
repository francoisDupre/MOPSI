#pragma once
#ifndef POLYNOME_H
#define POLYNOME_H

#include "Fonction.h"
#include <iostream>

class Polynome : public Fonction
{
public:
	Polynome();
	Polynome(float coeff[], unsigned int nb_coeff);

	float operator()(float x) const;
	Fonction* derivee() const;
	void afficher();
	float inverse(float y);

private:
	float _coeff[512];
	unsigned int _nb_coeff;
};


#endif