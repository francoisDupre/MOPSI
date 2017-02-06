#pragma once
#ifndef FONCTION_H
#define FONCTION_H

#include <iostream>
#include <cmath>

class Fonction
{
public:

	Fonction();
	Fonction(Fonction * integrale);

	virtual float operator()(float x) const;
	virtual Fonction* derivee() const;
	virtual float inverse(float y);
private:
	Fonction* _integrale;
};


#endif