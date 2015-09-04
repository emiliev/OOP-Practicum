#include "Worker.h"

Worker::Worker():name(NULL),egn(NULL),address(NULL),department(NULL), salary(0), type(tWorker)
{
    name = new char[1];
    name[0] = '\0';
    egn = new char[1];
    egn[0] = '\0';
    address = new char[1];
    address[0] = '\0';
    department = new char[1];
    department[0] = '\0';
}

Worker::Worker(char* newName, char* newEgn, char* newAddress, char* newDepartment, double newSalary):name(NULL),
    egn(NULL),address(NULL),department(NULL),type(tWorker){

    this->setName(newName);
    this->setEgn(newEgn);
    this->setAddress(newAddress);
    this->setDepartment(newDepartment);
    this->setSalary(newSalary);
}

Worker::Worker(Worker const &other):name(NULL),egn(NULL),address(NULL),department(NULL),type(tWorker){

    copyFrom(other);
}

Worker& Worker::operator=(Worker const &other){

    if(this != &other){
        destroy();
        copyFrom(other);
    }

    return *this;
}

Worker::~Worker()
{
    destroy();
}

void Worker::setName(char* newName){

    size_t length = strlen(newName) +1;
    this->name = new char[length];
    strcpy(name,newName);
}

void Worker::setAddress(char* newAddress){

    size_t length = strlen(newAddress) +1;
    this->address = new char[length];
    strcpy(address,newAddress);
}

void Worker::setEgn(char* newEgn){

    size_t length = strlen(newEgn) +1;
    this->egn = new char[length];
    strcpy(egn,newEgn);
}

void Worker::setDepartment(char* newDepartment){

    size_t length = strlen(newDepartment) + 1;
    this->department = new char[length];
    strcpy(department,newDepartment);
}

void Worker::setSalary(double newSalary){

    this->salary = newSalary;
}

char* Worker::getName(){

    return this->name;
}

char* Worker::getEgn(){

    return this->egn;
}

char* Worker::getAddress(){

    return this->address;
}

char* Worker::getDepartment(){

    return this->department;
}

double Worker::getSalary(){

    return this->salary;
}

workerType Worker::getType(){

    return this->type;
}
void Worker::copyFrom(Worker const &other){

    this->setName(other.name);
    this->setEgn(other.egn);
    this->setAddress(other.address);
    this->setDepartment(other.department);
    this->setSalary(other.salary);
    this->type = other.type;
}

void Worker::destroy(){

    std::cout<<"Worker::destroy()\n";
    delete [] this->name;
    delete [] this->egn;
    delete [] this->address;
    delete [] this->department;
}
