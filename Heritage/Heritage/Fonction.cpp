#include "Fonction.h"

using namespace std;

Fonction::Fonction()
{

}

Fonction::Fonction(Fonction * integrale)
{
	_integrale = integrale;
}

float Fonction::operator()(float x) const
{
	if (_integrale != 0)
	{
		double e = pow(10, -5);
		return (tan(x + e) - tan(x - e)) / (2 * e);
	}
	else return 0;
}

Fonction* Fonction::derivee() const
{
	return new Fonction();
}

float Fonction::inverse(float y)
{
	return 0;
}