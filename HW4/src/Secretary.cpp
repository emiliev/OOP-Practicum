#include "Secretary.h"

Secretary::Secretary():Worker(), list(NULL), numberOfLanguages(0)
{

}

Secretary::Secretary(char* newName,char* newEgn, char* newAddress, char* newDepartment,
                        double newSalary, char** newLanguages,size_t newNumber):
                        Worker(newName, newEgn, newAddress, newDepartment, newSalary), list(NULL){

    this->setNumberOfLanguages(newNumber);
    this->setList(newLanguages);
}

Secretary::Secretary(Secretary const &other): list(NULL){

    this->copyFrom(other);
}

Secretary& Secretary::operator=(Secretary const &other){

        if(this != &other){
            destroy();
            copyFrom(other);
        }

    return *this;
}

Secretary::~Secretary()
{
    destroy();
}

void Secretary::setNumberOfLanguages(size_t num){

    this->numberOfLanguages = num;
}

void Secretary::setList(char** languages){

    this->list = new char*[numberOfLanguages];
    for(int index = 0; index < numberOfLanguages; ++index){

        size_t length = strlen(languages[index]) + 1;
        this->list[index] = new char[length];
        strcpy(list[index],languages[index]);
    }
}

size_t Secretary::getNumberOfLanguages(){

    return this->numberOfLanguages;
}

void Secretary::printList(char** languages){

    for(int index = 0; index < numberOfLanguages; ++index){

        std::cout<<list[index]<<" ";
    }
    std::cout<<std::endl;
}

void Secretary::destroy(){

    for(int index = 0; index < numberOfLanguages; ++index){

        delete [] this->list[index];
    }

    delete [] this->list;
}

void Secretary::copyFrom(Secretary const &other){

    Worker::copyFrom(other);
    this->setNumberOfLanguages(other.numberOfLanguages);
    this->setList(other.list);
}
