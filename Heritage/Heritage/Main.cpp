#include "Fonction.h"
#include "Polynome.h"
#include "Affine.h"
#include "Trigo.h"

using namespace std;

int main()
{
	float coeff[4];
	
	float val1 = 0;
	coeff[0] = val1;
	coeff[1] = 0;
	coeff[2] = 0;
	coeff[3] = 1;

	Polynome p = Polynome(coeff, 4);
	
	cout << p(3) << endl;
	p.afficher();

	cout << p.inverse(27) << endl;

	Affine a = Affine(2, 2);
	cout << a(2) << endl;

	cout << a.inverse(18) << endl;
	
	/*Polynome *p1 = (Polynome*)(a.derivee());

	p1->afficher();

	Polynome *p2 = (Polynome*)(p.derivee());
	p2->afficher();
	*/

	Trigo tr = Trigo("tan");

	cout << tr(3.14) << endl;
	float val = 4 * atan(1);
	cout << tr.inverse(val) << endl;

	int t;
	cin >> t;
}