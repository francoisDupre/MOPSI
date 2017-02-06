#include<iostream>
#include "neighbors.h"
#include <utility>
#include <stack>






template <typename T>
int search(vector<Point2D<T>> &neighbors,
	   QuadTree<Point2D<T>>* qtree, Square s,
	   Point2D<T> p);
