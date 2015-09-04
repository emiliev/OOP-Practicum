#include "Group.h"

Group::Group()
{
    this->setX1(0);
    this->setY1(0);
    this->setNumberOfShapes(1);
    this->currentPosition = 0;
}

Group::Group(double numX1, double numY1){

    this->setX1(numX1);
    this->setY1(numY1);
    this->setNumberOfShapes(1);
    this->currentPosition = 0;
    this->shapes = new Shape*[numberOfShapes];
}

Group::Group(Group const &other){

    copyFrom(other);
    this->currentPosition = other.currentPosition;
}

Group& Group::operator=(Group const &other){

    if(this != &other){
        this->currentPosition = other.currentPosition;
        copyFrom(other);
    }

    return *this;
}

Group::~Group()
{

}

void Group::translation(){

    for(int index = 0; index < currentPosition; ++index){
        shapes[index]->returnCoordinates();
        shapes[index]->setNewCords(x1,y1);
        std::cout<<"After translation:\n";
        shapes[index]->returnCoordinates();
        shapes[index]->isContaining(2,2);
    }
}

void Group::resizeShapes(){

   Shape** newShapes = new Shape*[numberOfShapes + 1];
    for(size_t index = 0; index < numberOfShapes; ++index){
        newShapes[index] = shapes[index];
    }

    delete [] this->shapes;

    ++numberOfShapes;
    this->shapes = newShapes;
}

void Group::addShape(Shape *newShape){

    if(currentPosition == numberOfShapes){

        resizeShapes();
    }

    this->shapes[currentPosition] = newShape;
    ++currentPosition;
}

void Group::setNumberOfShapes(size_t number){

    this->numberOfShapes = number;
}

size_t Group::getNumberOfShapes(){

    return this->numberOfShapes;
}

void Group::setNewCords(double x1, double x2){

}

void Group::returnCoordinates(){
}

void Group::copyFrom(Group const &other){

   this->setNumberOfShapes(other.numberOfShapes);
   this->currentPosition = other.currentPosition;
   this->shapes = new Shape*[other.numberOfShapes];
   for(int index = 0; index < numberOfShapes; ++index){

        this->addShape(other.shapes[index]);
   }
}

bool Group::isContaining(double a, double b){

    return true;
}
