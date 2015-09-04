#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle: public Shape
{
    public:
        Rectangle();
        Rectangle(double, double, double, double);
        Rectangle(Rectangle const &);
        Rectangle& operator=(Rectangle const &);
        ~Rectangle();

        void setX2(double);
        void setY2(double);


        double getX2();
        double getY2();

        bool isContaining(double , double );
        void setNewCords(double, double);
        void returnCoordinates();
    protected:
    private:

        double x2,y2;
        void copyFrom(Rectangle const &);

};

#endif // RECTANGLE_H
