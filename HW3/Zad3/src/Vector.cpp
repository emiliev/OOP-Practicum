#include "Vector.h"

Vector::Vector(): a(NULL){
    this->length = 3;
    this->setA(length);
}

Vector::Vector(int number): a(NULL){
    this->length = number;
    this->setA(length);
}

Vector::Vector(const Vector& other){

    this->length = other.length;
    this->a = new double[length];

    for(int index = 0; index < this->length; ++index){
        this->a[index] = other.a[index];
    }
}

Vector::~Vector()
{
    delete [] a;
}

void Vector::setA(int num){

    this->a = new double[num];

    for(int index = 0; index < num; ++index){

        std::cin>>this->a[index];
    }
}

void Vector::setLength(int number){

    if(number > 0){

        this->length = number;
    }
    else{
        this-> length = 10;
    }
}

int Vector::getLength(){

    return this->length;
}

void Vector::printVector(){

    for(int index = 0; index < this->length; ++index){

        std::cout<<this->a[index]<<" ";
    }
    std::cout<<std::endl;
}

double Vector::operator[](int index){
    if(index < length && index >= 0){

        return this->a[index];
    }

    return 0.0;
}

Vector Vector::operator+(Vector& leftVector){

    Vector sum = *this;
    //sum.compareLength(this);
    sum += leftVector;
return sum;
}

Vector& Vector::operator+=(Vector& leftVector){

    this->compareLength(leftVector);
    for(int index = 0; index < this->getLength(); ++index){

        this->a[index] += leftVector.a[index];
    }

    return *this;
}

Vector& Vector::operator-(Vector& otherV){

    this->compareLength(otherV);
    if(this->getLength() == otherV.getLength()){

        for(int index = 0; index < this->length; ++index){

            this->a[index] -=otherV.a[index];
        }
    }

    return *this;
}

Vector& Vector::operator-=(Vector& otherV){


    return this->operator-(otherV);
}

Vector& Vector::operator*(double digit){

    for(int index = 0; index < this->length; ++index){

        this->a[index] *= digit;
    }

    return *this;
}

Vector& Vector::operator*=(double digit){

    return this->operator*(digit);
}

Vector& Vector::operator/(double digit){

    for(int index = 0 ;index < this->length; ++index){

        this->a[index] /= digit;
    }

    return *this;
}

Vector& Vector::operator/= (double digit){

    return this->operator/(digit);
}

double Vector::operator%(Vector& otherV){

    this->compareLength(otherV);
    double product = 0;
    if(this->getLength() == otherV.getLength()){

        for(int index = 0; index < this->length; ++index){

            product += this->a[index] * otherV.a[index];
        }
    }

    return product;
}

Vector Vector::operator=( Vector& otherV){

    if(this != &otherV){

        this->compareLength(otherV);
        delete [] this->a;
        this->setLength(otherV.length);
        this->a = new double[this->length];
        for(int index = 0; index < this->length; ++index){

            this->a[index] = otherV.a[index];
        }
    }

    return *this;
}

void Vector::compareLength( Vector& otherV){

    if(this->getLength() > otherV.getLength()){
        resizeArray(otherV,this->getLength());
    }
    else{
        resizeArray(*this,otherV.getLength());
    }
}

void Vector::resizeArray(Vector& otherV,int newLength){

    double* newArr = new double[newLength];
    for(int index = 0; index < otherV.getLength(); index++){

        newArr[index] = otherV.a[index];
    }
    for(int index = otherV.getLength(); index < newLength; ++index){
        newArr[index] = 0;
    }
    otherV.setLength(newLength);

    delete [] otherV.a;
    otherV.a = newArr;
}
