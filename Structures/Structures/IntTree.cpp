#include "IntTree.h"

using namespace std;

 // Create a node with given information
IntTree::IntTree(int d)
{
	this->data = d;
	this->sons = vector<IntTree*>();
}
// Destruct a node and all its descendants
IntTree::~IntTree()
{
	
}

// Return information of this node
int IntTree::getData()
{
	return this->data;
}
// Set information of this node
void IntTree::setData(int d)
{
	this->data = data;
}
// Return the number of sons of this node
int IntTree::nbSons()
{
	return this->sons.size();
}
// Return the son at position pos, if any (considering left-most son is at position 0)
IntTree* IntTree::getSon(int pos)
{
	return this->sons.at(pos);
}
// Replace the exisiting son at position pos with newSon (left-most son at position 0) 
void IntTree::setSon(int pos, IntTree* newSon)
{
	this->sons.at(pos) = newSon;
}
// Add newSon as supplementary right-most son of this node
void IntTree::addAsLastSon(IntTree* newSon)
{
	this->sons.push_back(newSon);
}
// Remove right-most son of this node
void IntTree::removeLastSon()
{
	this->sons.pop_back();
}
//Display the tree
void IntTree::display(string prefix,
 						string indent)
{
	int i;

	cout << prefix;
	cout << this->data << endl;
	
	if(this->sons.size() > 0)	
		for(i = 0; i < this->sons.size(); i++)
			(this->sons.at(i))->display(prefix + indent, indent);
	
}

