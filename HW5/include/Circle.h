#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle: public Shape
{
    public:
        Circle();
        Circle(double, double, double );
        Circle(Circle const &);
        Circle& operator=(Circle const &);
        ~Circle();


        void setRadius(double);
        double getRadius();
        bool isContaining(double, double);
        void setNewCords(double, double);
        void returnCoordinates();
    protected:
    private:

        double radius;
        void copyFrom(Circle const &);
};

#endif // CIRCLE_H
