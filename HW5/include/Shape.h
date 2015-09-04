#ifndef SHAPE_H
#define SHAPE_H

#include <cmath>
#include <iostream>

enum shapeType{typeCircle, typeTriangle, typeRectangle};
class Shape
{
    public:
        Shape();
        virtual ~Shape();

        void setX1(double);
        void setY1(double);

        double getX1();
        double getY1();
        shapeType getType();
        void copyFrom(Shape const &);
        virtual bool isContaining(double, double) = 0;
        virtual void setNewCords(double, double) = 0;
        virtual void returnCoordinates() = 0;
    protected:
        double x1,y1;
        shapeType typeOfShape;
    private:
};

#endif // SHAPE_H
