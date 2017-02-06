#include "Affine.h"

using namespace std;
Affine::Affine(float a, float b) : Polynome()
{
	if (a != 0)
	{
		_a = a;
		_b = b;
	}
	else
	{
		cout << "Wrong value : a must be not null" << endl;
	}
}

float Affine::operator()(float x) const
{
	return _a*x + _b;
}

Fonction* Affine::derivee() const
{
	float coeff[1];
	coeff[0] = _a;
	Polynome *p = new Polynome(coeff, 1);
	return p;
}

float Affine::inverse(float y)
{
	float x = 1;
	float x_temp = 0;
	Affine* derivee = (Affine*)this->derivee();
	int i = 0;

	while (abs(x - x_temp) > pow(10, -5)) {
		x_temp = x;
		x = x + ((y - this->operator()(x)) / derivee->operator()(x));

		i++;
	}
	return x;
}