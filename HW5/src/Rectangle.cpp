#include "Rectangle.h"

Rectangle::Rectangle()
{
    this->setX2(0);
    this->setY2(3);
    this->typeOfShape = typeRectangle;
}

Rectangle::Rectangle(double numX1, double numX2, double numY1, double numY2){

    this->setX1(numX1);
    this->setX2(numX2);
    this->setY1(numY1);
    this->setY2(numY2);
    this->typeOfShape = typeRectangle;
}

Rectangle::Rectangle(Rectangle const &other){

    copyFrom(other);
}

Rectangle& Rectangle::operator=(Rectangle const &other){

    if(this != &other){

        copyFrom(other);
    }

    return *this;
}

Rectangle::~Rectangle()
{

}

void Rectangle::setX2(double numX2){

    this->x2 = numX2;
}

void Rectangle::setY2(double numY2){

    this->y2 = numY2;
}

double Rectangle::getX2(){

    return this->x2;
}

double Rectangle::getY2(){

    return this->y2;
}

void Rectangle::returnCoordinates(){

   std::cout<<"Rectagle: "<<this->getX1()<<" "<<this->getY1()<<" "<<this->getX2()<<" "<<this->getY2()<<std::endl;
}

void Rectangle::setNewCords(double newX, double newY){

    this->setX1(x1 + newX);
    this->setY1(y1 + newY);
    this->setX2(x2 + newX);
    this->setY2(y2 + newY);
}

bool Rectangle::isContaining(double numX1, double numY1){


    if(numX1 >= this->getX1() && numX1 <= this->getX2() && numY1 >= this->getY1() && numY1 <= this->getY2()){
        std::cout<<"INSIDE the rectangle!\n";
        return true;
    }

    std::cout<<"OUTSIDE the rectangle!\n";
    return false;
}

void Rectangle::copyFrom(Rectangle const &other){

    Shape::copyFrom(other);
    this->typeOfShape = typeRectangle;
    this->setX2(other.x2);
    this->setY2(other.y2);
}
