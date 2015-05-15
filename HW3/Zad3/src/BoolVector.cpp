#include "BoolVector.h"

BoolVector::BoolVector()
{
    for(int index = 0 ;index < 32; ++index){
        this->boolArray[index] = 0;
    }

    std::cout<<sizeof(this->boolArray)<<std::endl;
}

BoolVector::~BoolVector()
{

}

void BoolVector::printArray(){

    for(int index = 0 ;index < 32; ++index){

        std::cout<<this->boolArray[index]<<" ";
    }
    std::cout<<std::endl;
}

bool BoolVector::operator[](int index){

    if(!isValid(index)){
        return false;
    }
    return this->boolArray[index];
}

bool BoolVector::set(int index){

    if(!isValid(index)){
        return false;
    }

    this->boolArray[index] = 1;
    return true;
}


bool BoolVector::clear(int index){

    if(!isValid(index)){
        return false;
    }

    this->boolArray[index] = 0;
    return true;
}

bool BoolVector::isValid(int index){

    if(index >= 0 && index < 32){
        return true;
    }

    return false;
}
