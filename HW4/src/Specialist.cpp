#include "Specialist.h"

Specialist::Specialist(): Worker(),description(NULL)
{
    this->type = tSpecialist;
    description = new char[1];
    this->description[0] = '\0';
}

Specialist::Specialist(char* newName,char* newEgn, char* newAddress, char* newDepartment,
                        double newSalary, char* newDescription):
                        Worker(newName, newEgn, newAddress, newDepartment, newSalary), description(NULL){

    this->setDescription(newDescription);
    this->type = tSpecialist;
}

Specialist::Specialist(Specialist const &other){

    copyFrom(other);
    this->type = tSpecialist;
}

Specialist& Specialist::operator=(Specialist const &other){

    if(this != &other){
        destroy();
        copyFrom(other);
    }

    return *this;
}

Specialist::~Specialist()
{
    destroy();
}

void Specialist::setDescription(char* newDescription){

    size_t length = strlen(newDescription) + 1;
    this->description = new char[length];
    strcpy(description,newDescription);
}

char* Specialist::getDescription(){

    return this->description;
}

void Specialist::destroy(){

    std::cout<<"Specialist::destroy()\n";
    delete [] this->description;
}

void Specialist::copyFrom(Specialist const &other){

    Worker::copyFrom(other);
    this->setDescription(other.description);
    this->type = tSpecialist;
}
