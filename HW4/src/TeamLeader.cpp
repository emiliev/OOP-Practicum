#include "TeamLeader.h"

TeamLeader::TeamLeader():Specialist(), departmentInformation(NULL), team(NULL)
{
    this->type = tTeamLeader;
    this->departmentInformation = new char[1];
    departmentInformation[0] = '\0';
}

TeamLeader::TeamLeader(char* newName, char* newEgn, char* newAddress, char* newDepartment,
                        double newSalary, char* newDescription, char* newDepartmentInformation):
                            Specialist(newName,newEgn,newAddress,newDepartment,newSalary,newDescription),
                             departmentInformation(NULL),team(NULL)
{

    this->setDepartmentInformation(newDepartmentInformation);
    this->type = tTeamLeader;
}

TeamLeader::TeamLeader(TeamLeader const &other):Specialist(other),departmentInformation(NULL),team(NULL){

    copyFrom(other);
    this->type = tTeamLeader;
}

TeamLeader& TeamLeader::operator=(TeamLeader const &other){

    if(this != &other){

        copyFrom(other);
    }

    return *this;
}

TeamLeader::~TeamLeader()
{
    destroy();
}

void TeamLeader::setDepartmentInformation(char* newInfo){

    size_t length = strlen(newInfo) + 1;
    this->departmentInformation = new char[length];
    strcpy(departmentInformation,newInfo);
}

void TeamLeader::addWorkers(Worker **workers, int length){

    this->members = 0;
    for(int index = 0; index < length; ++index){

        if(strcmp(workers[index]->getDepartment(), this->getDepartment()) == 0){
            ++members;
            resizeTeam(members);
            team[members - 1] = workers[index];
        }
    }
}

void TeamLeader::resizeTeam(int length){

    Worker** newTeam = new Worker*[length];
    for(int index = 0; index < length - 1; ++index){

        newTeam[index] = team[index];
    }

    delete [] this->team;
    this->team =  newTeam;
    delete [] newTeam;
}

void TeamLeader::printMembers(){

    for(int index = 0; index < members; ++index){

        std::cout<<team[index]->getName()<<std::endl;
    }
}

char* TeamLeader::getDepartmentInformation(){

    return this->departmentInformation;
}

void TeamLeader::destroy(){

    delete [] this->departmentInformation;
    delete [] this->team;
}

void TeamLeader::copyFrom(TeamLeader const &other){

    Specialist::copyFrom(other);
    this->setDepartmentInformation(other.departmentInformation);
    this->type = tTeamLeader;
}

