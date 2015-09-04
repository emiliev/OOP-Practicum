#ifndef GROUP_H
#define GROUP_H

#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Shape.h"

class Group: public Shape
{
    public:
        Group();
        Group(double, double);
        Group(Group const &);
        Group& operator=(Group const &);
        ~Group();

        void setNumberOfShapes(size_t);
        size_t getNumberOfShapes();
        void addShape(Shape* shape);
        void translation();
        bool isContaining(double, double);
        void setNewCords(double, double);
        void returnCoordinates();
    protected:
    private:

        Shape** shapes;
        size_t numberOfShapes;
        size_t currentPosition;
        void destroy();
        void resizeShapes();
        void copyFrom(Group const &);
};

#endif // GROUP_H
