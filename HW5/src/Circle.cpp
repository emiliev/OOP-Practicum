#include "Circle.h"

Circle::Circle()
{
    this->typeOfShape = typeCircle;
    this->setRadius(1);
}

Circle::Circle(double radius,double numX1, double numY1){

    this->typeOfShape = typeCircle;
    this->setRadius(radius);
    this->setX1(numX1);
    this->setY1(numY1);
}

Circle::Circle(Circle const &other){

    copyFrom(other);
}

Circle& Circle::operator=(Circle const &other){

    if(this != &other){

        copyFrom(other);
    }

    return *this;
}

Circle::~Circle()
{

}

void Circle::setRadius(double num){

    this->radius = num;
}

double Circle::getRadius(){

    return this->radius;
}

void Circle::returnCoordinates(){

    std::cout<<"Circle: "<<this->getX1()<<" "<<this->getY1()<<std::endl;
}

bool Circle::isContaining(double numX1, double numY1){

    double differenceByX = numX1 - this->getX1();
    double differenceByY = numY1 - this->getY1();
    double result = sqrt(pow(differenceByX,2) + pow(differenceByY,2));
    if(result <= this->getRadius()){
        std::cout<<"INSIDE the circle\n";
        return true;
    }
    std::cout<<"OUTSIDE the circle\n";
    return false;
}

void Circle::setNewCords(double newX, double newY){

    this->setX1(x1 + newX);
    this->setY1(y1 + newY);
}

void Circle::copyFrom(Circle const &other){

    Shape::copyFrom(other);
    this->setRadius(other.radius);
    this->typeOfShape = typeCircle;
}
