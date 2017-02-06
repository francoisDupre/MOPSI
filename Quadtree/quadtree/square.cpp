#include<iostream>
#include "square.h"

Square Square::subsquare(int dir)
{
    switch(dir)
    {
    case 0:
        return Square(x,y+w/2,w/2) ;
        break ;
    case 1:
        return Square(x+w/2,y+w/2,w/2) ;
        break ;
    case 2:
        return Square(x+w/2,y,w/2) ;
        break ;
    case 3:
        return Square(x,y,w/2);
        break ;
    default:
        std::cerr << "dir must be between 0 and 3" << std::endl ;
        break ;
    }
}


bool Square::intersects_disk(Point_2D p, float r)
{
    return     ((p.x()>=x-r)&&(p.x()<=x+w+r)&&(p.y()>=y)&&(p.y()<=y+w))
            || ((p.x()>=x)&&(p.x()<=x+w)&&(p.y()<=y-r)&&(p.y()>=y+w+r))
            || (p.dist2(Point_2D(x,y)) <= r*r)
            || (p.dist2(Point_2D(x+w,y)) <= r*r)
            || (p.dist2(Point_2D(x,y+w)) <= r*r)
            || (p.dist2(Point_2D(x+w,y+w)) <= r*r) ;
}
