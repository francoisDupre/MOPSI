#pragma once

#include <vector>
#include <cmath>

#include "point2d.h"
#include "square.h"
#include "quadrant.h"
#include "quadtree.h"
#include "stack"

using std::vector ;
using std::stack ;


//
// Add point p in the quadtree representing the points in square s
//

template <typename T>
void insert(QuadTree<Point2D<T>>* &qtree, Square s, Point2D<T> p)
{
    if (!qtree)
        {
            qtree = new QuadLeaf<Point2D<T>>(p) ;

            //*qtree = QuadLeaf<Point2D<T>>(p) ;
        }
    else
    {
        if (qtree->isLeaf())
        {
            Point2D<T> p1(qtree->value()) ;
            if (p!=p1)
            {
                Quadrant q(s,p) ;
                Quadrant q1(s,p1) ;
                /*
                delete qtree ;
                QuadTree<Point2D<T>>* qtree1 ;
                qtree1 = new QuadNode<Point2D<T>>() ;
                qtree = qtree1 ;
                */
                delete qtree ;
                qtree = new QuadNode<Point2D<T>>() ;
                insert(qtree->son(q1.dir),q1.ssq,p1) ;
                insert(qtree->son(q.dir),q.ssq,p) ;
            }
        }
        else
        {
            Quadrant q(s,p) ;
            insert(qtree->son(q.dir),q.ssq,p) ;
        }
    }
}

//
// Add in vector neighbors the points q in quadtree qtree representing
// points in square s at euclidean distance less than r from point p
//
// Set only the nearest point if nearest is true
//
// Return the number of nodes visited
//

template <typename T>
int search(vector<Point2D<T>> &neighbors,
	   QuadTree<Point2D<T>>* qtree, Square s,
	   Point2D<T> p, float& r, bool nearest = false)
{
    if (qtree)
    {
        if (qtree->isLeaf())
        {
            Point2D<T> q(qtree->value()) ;
            if (!(p==q))
            {
            float distance(p.dist(q)) ;
            if (distance <= r)
            {

                if (nearest)
                {
                    r = distance ;
                }
                neighbors.push_back(q) ;
            }
            }
            return 1 ;
        }
        else
        {
            int numberNodesVisited(0) ;
            for (int i=0 ; i < nbQuadDir ; i++)
            {
                Square ss = s.subsquare(i) ;
                if (ss.intersects_disk(p,r))
                {
                    numberNodesVisited +=search(neighbors,qtree->son(i),ss,p,r,nearest);
                }
            }
            return numberNodesVisited+1 ;
        }
    }
    else
    {
           return 0 ;
    }
}

//
// Add in vector neighbors the nearest point of p in the quadtree qtree
// representing the points in square s
//
// Return the number of nodes visited
//
template <typename T>
int search(vector<Point2D<T>> &neighbors,
	   QuadTree<Point2D<T>>* qtree, Square s,
	   Point2D<T> p)
	   {
        float r = s.w+1 ;
        return search(neighbors,qtree,s,p,r,true) ;
	   }


Town linearSearch(vector<Town> towns,float& r,Town ville)
{
    Town closestTown ;
    Point2D<string> p = ville.point() ;
    for (vector<Town>::iterator it = towns.begin() ; it != towns.end() ; it++)
    {
        Point2D<string> q = (*it).point() ;
        if (p.dist2(q) < r)
        {
            r = p.dist2(q) ;
            closestTown = *it ;
        }
    }
    return closestTown ;
}


