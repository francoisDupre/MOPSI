#include "Trigo.h"

using namespace std;



Trigo::Trigo(string func, bool neg) : Fonction()
{
	if (func.compare("cos") == 0)
		_func = "cos";
	else if (func.compare("sin") == 0)
		_func = "sin";
	else if (func.compare("tan") == 0)
		_func = "tan";
	else
	{
		cout << "Wrong function name : cos, sin or tan only" << endl;
	}
	_neg = neg;
}

float Trigo::operator()(float x) const
{
	if (_func.compare("cos") == 0)
	{
		if (_neg)
			return -cos(x);
		else
			return cos(x);
	}
		
	else if (_func.compare("sin") == 0)
	{
		if (_neg)
			return -sin(x);
		else
			return sin(x);
	}
	else if (_func.compare("tan") == 0)
	{
		if (_neg)
			return -tan(x);
		else
			return tan(x);
	}
	else
	{
		cout << "Wrong function name : cos, sin or tan only" << endl;
		return 0;
	}
}

Fonction* Trigo::derivee() const
{
	if (_func.compare("cos") == 0)
		return new Trigo("sin", true);
	else if (_func.compare("sin") == 0)
		return new Trigo("cos");
	else if (_func.compare("tan") == 0)
		return new Fonction(new Trigo("tan"));
}

float Trigo::inverse(float y) 
{
	float x = 1;
	float x_temp = 0;

	Fonction* derivee;
	if (_func.compare("tan") != 0)
		derivee = (Trigo*)this->derivee();
	else
		derivee = this->derivee();

	int i = 0;
	cout << "value : " << this->operator()(y) << endl;
	cout << "derivee : " << derivee->operator()(y) << endl;
	while (abs(x - x_temp) > pow(10, -5) && i < 100) {
		x_temp = x;
		x = x + ((y - this->operator()(x)) / derivee->operator()(x));
		
		i++;
	}
	return x;
}