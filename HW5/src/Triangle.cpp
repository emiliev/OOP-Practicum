#include "Triangle.h"

#include <iostream>

Triangle::Triangle()
{
    typeOfShape = typeTriangle;
    this->setX1(0);
    this->setY1(0);
    this->setX2(1);
    this->setY2(1);
    this->setX3(2);
    this->setY3(0);
}

Triangle::Triangle(double numX, double numY, double numX1, double numY1,double numX2, double numY2){

    this->setX1(numX);
    this->setY1(numY);
    this->setX2(numX1);
    this->setY2(numY1);
    this->setX3(numX2);
    this->setY3(numY2);
    typeOfShape = typeTriangle;
}

Triangle::Triangle(Triangle const &other){

    copyFrom(other);
}

Triangle& Triangle::operator=(Triangle const &other){

    if(this != &other){

        copyFrom(other);
    }
    return *this;
}

Triangle::~Triangle()
{

}

void Triangle::setX2(double num){

    this->x2 = num;
}

void Triangle::setX3(double num){

    this->x3 = num;
}

void Triangle::setY2(double num){

    this->y2 = num;
}

void Triangle::setY3(double num){

    this->y3 = num;
}


double Triangle::getX2(){

    return this->x2;
}

double Triangle::getX3(){

    return this->x3;
}

double Triangle::getY2(){

    return this->y2;
}

double Triangle::getY3(){

    return this->y3;
}

void Triangle::returnCoordinates(){

    std::cout<<"Triangle: "<<this->getX1()<<" "<<this->getY1()<<" "<<this->getX2()
             <<" "<<this->getY2()<<" "<<this->getX3()<<" "<<this->getY3()<<std::endl;
}

double Triangle::calculateArea(double numX1, double numX2, double numX3, double numY1, double numY2, double numY3){

    double area = (numX1*(numY2 - numY3) + numX2*(numY3 - numY1) + numX3*(numY1 - numY2)) / 2;
    return area;
}

bool Triangle::isContaining(double numX1, double numY1){

    double areaOfTriangle = calculateArea(x1,x2,x3,y1,y2,y3);

    double subArea1 = calculateArea(x1,x2,numX1,y1,y2,numY1);
    double subArea2 = calculateArea(x1,numX1,x3,y1,numY1,y3);
    double subArea3 = calculateArea(numX1,x2,x3,numY1,y2,y3);

    if(areaOfTriangle == subArea1 + subArea2 + subArea3){
        std::cout<<"INSIDE the triangle!\n";
        return true;
    }
     std::cout<<"OUTSIDE the triangle!\n";
    return false;
}

void Triangle::setNewCords(double newX, double newY){

    this->setX1(x1 + newX);
    this->setX2(x2 + newX);
    this->setX3(x3 + newX);
    this->setY1(y1 + newY);
    this->setY2(y2 + newY);
    this->setY3(y3 + newY);
}

void Triangle::copyFrom(Triangle const &other){

    Shape::copyFrom(other);
    this->setX2(other.x2);
    this->setY2(other.y2);
    this->setX3(other.x3);
    this->setY3(other.y3);
    this->typeOfShape = typeTriangle;
}
