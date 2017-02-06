#pragma once
#ifndef AFFINE_H
#define AFFINE_H

#include <iostream>
#include "Polynome.h"

class Affine : public Polynome
{
public:
	Affine(float a, float b);

	float operator()(float x) const;
	Fonction* derivee() const;
	float inverse(float y);

private:
	float _a;
	float _b;

};

#endif
