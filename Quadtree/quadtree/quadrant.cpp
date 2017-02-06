#include "quadrant.h"
#include <iostream>


Quadrant::Quadrant(Square s, Point_2D p)
{
    float x=s.x ;
    float y=s.y ;
    float w=s.w ;
    float px=p.x() ;
    float py=p.y() ;
    if ((px < x) || (px > x+w) || (py < y) || (py > y+w))
    {
        std::cerr << "p doesn't belong to s" << std::endl ;
    }
    else if ((px <= x+w/2) && (py >= y+w/2))
    {
        dir=0;
        ssq=s.subsquare(0) ;
    }
    else if ((px > x+w/2) && (py >= y+w/2))
    {
        dir=1;
        ssq=s.subsquare(1) ;
    }
    else if ((px >= x+w/2) && (py < y+w/2))
    {
        dir=2;
        ssq=s.subsquare(2) ;
    }
    else if ((px < x+w/2) && (py < y+w/2))
    {
        dir=3;
        ssq=s.subsquare(3) ;
    }
}
