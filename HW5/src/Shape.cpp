#include "Shape.h"


Shape::Shape()
{

}

Shape::~Shape()
{

}

void Shape::setX1(double num){

    this->x1 = num;
}

void Shape::setY1(double num){

    this->y1 = num;
}

double Shape::getY1(){

    return this->y1;
}

double Shape::getX1(){

    return this->x1;
}

shapeType Shape::getType(){

    return this->typeOfShape;
}

void Shape::copyFrom(Shape const &other){

    this->setX1(other.x1);
    this->setY1(other.y1);
}
