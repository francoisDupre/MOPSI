#include "IntTree.h"

using namespace std;

int main()
{
	IntTree* root = new IntTree(12);
	root->addAsLastSon(new IntTree(8));
	root->getSon(0)->addAsLastSon(new IntTree(4));
	root->getSon(0)->addAsLastSon(new IntTree(9));
	root->addAsLastSon(new IntTree(23));
	root->getSon(1)->addAsLastSon(new IntTree(17));
	root->getSon(1)->getSon(0)->addAsLastSon(new IntTree(15));

	root->display("* ");
	delete root;
	return 0;
}