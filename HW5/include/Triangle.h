#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle: public Shape
{
    public:
        Triangle();
        Triangle(double, double, double, double, double, double);
        Triangle(Triangle const &);
        Triangle& operator=(Triangle const &);
        ~Triangle();


        void setX2(double);
        void setX3(double);
        void setY2(double);
        void setY3(double);


        double getX2();
        double getX3();
        double getY2();
        double getY3();

        bool isContaining(double , double );
        void setNewCords(double, double);
        void returnCoordinates();
        double calculateArea(double,double,double,double,double,double);
    protected:
    private:

        double x2,y2,x3,y3;
        void copyFrom(Triangle const &);

};

#endif // TRIANGLE_H
