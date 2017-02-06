#include "Polynome.h"

using namespace std;

Polynome::Polynome() : Fonction()
{

}

Polynome::Polynome(float coeff[], unsigned int nb_coeff) : Fonction()
{
	int i;
	/*for (i = 0; i < nb_coeff; i++)
	{
		if (coeff[i] == NULL)
		{
			cout << i + 1 << " : Wrong expression format : the size is not correct" << endl;
			return;
		}
	}*/
	for (i = 0; i < nb_coeff; i++)
		_coeff[i] = coeff[i];

	_nb_coeff = nb_coeff;
}

float Polynome::operator()(float x) const
{
	int x_res[512];
	int i,j;
	int x_pow;
	
	float res;

	for (i = _nb_coeff - 1; i > 0; i--)
	{
		x_pow = 1;
		for (j = i; j > 0; j--)
		{
			x_pow *= x;
		}
		x_res[i] = x_pow;
	}

	
	res = _coeff[0];
	for (i = 1; i < _nb_coeff; i++)
	{
		res += _coeff[i] * x_res[i];
	}

	return res;
}

void Polynome::afficher()
{
	int i;

	for (i = _nb_coeff - 1; i > 0; i--)
	{
		if (_coeff[i] >= 0)
			cout << "+" << _coeff[i] << "*x^" << i << " ";
		else
			cout << _coeff[i] << "*x^" << i << " ";
	}
	if (_coeff[0] >= 0)
		cout << "+" << _coeff[0] << endl;
	else
		cout << _coeff[0] << endl;
}

Fonction* Polynome::derivee() const
{
	float coeff[512];
	float nb_coeff = _nb_coeff - 1;
	int i;

	for (i = nb_coeff - 1; i >= 0; i--)
	{
		coeff[i] = _coeff[i + 1] * (i + 1);
	}
	Polynome*p = new Polynome(coeff, nb_coeff);

	return p;
}

float Polynome::inverse(float y)
{
	float x = 1;
	float x_temp = 0;
	Polynome* derivee = (Polynome*)this->derivee();
	int i = 0;
	
	while (abs(x - x_temp) > pow(10, -5)) {
		x_temp = x;
		x = x + ((y - this->operator()(x)) / derivee->operator()(x));
		
		i++;
	}
	return x;
}