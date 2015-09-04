#include "Director.h"

Director::Director():workers(NULL),numberOfWorkers(0),numberOfSpecialists(0), numberOfTeamLeaders(0)
{

}

Director::Director(Secretary &newSecretary, Worker **newWorkers, size_t workersNumber,
                    size_t leadersNumber, size_t specialistNumber, int createdWorkers):workers(NULL){

    this->setNumberOfWorkers(workersNumber);
    this->setNumberOfTeamLeaders(leadersNumber);
    this->setNumberOfSpecialists(specialistNumber);
    this->createdWorkers = createdWorkers;
    this->setSecretary(newSecretary);
    this->addWorkers(newWorkers);
}

Director::Director(Director const &other): workers(NULL){

    this->copyFrom(other);
}

Director& Director::operator=(Director const &other){

    if(this != &other){
        destroy();
        copyFrom(other);
    }

    return *this;
}

Director::~Director()
{
    destroy();
}

void Director::showAllWorkers(){

    int allWorkers = numberOfSpecialists + numberOfTeamLeaders + numberOfWorkers;

    for(size_t index = 0 ; index < allWorkers; ++index){

        std::cout<<workers[index]->getName()<<std::endl;
    }
}

double Director::paySalary(){

    int sum = 0;
    int allWorkers = numberOfSpecialists + numberOfTeamLeaders + numberOfWorkers;
    for(size_t index = 0; index < allWorkers; ++index){

        sum +=workers[index]->getSalary();
    }

    return sum;
}

size_t Director::getNumberOfWorkers(){

    return this->numberOfWorkers;
}

size_t Director::getNumberOfSpecialists(){

    return this->numberOfSpecialists;
}

size_t Director::getNumberOfTeamLeaders(){

    return this->numberOfTeamLeaders;
}

void Director::setNumberOfTeamLeaders(size_t number){

    this->numberOfTeamLeaders = number;
}

void Director::setNumberOfSpecialists(size_t number){

    this->numberOfSpecialists = number;
}

void Director::setNumberOfWorkers(size_t number){
    this->numberOfWorkers = number;
}

void Director::addWorkers(Worker** allWorkers){

    int currentPossition = 0;
    int currentWorkers = numberOfWorkers;
    int currentLeaders = numberOfTeamLeaders;
    int currentSpecialists = numberOfSpecialists;
    this->workers = new Worker*[numberOfWorkers + numberOfTeamLeaders + numberOfSpecialists];
    for(int index = 0; index < createdWorkers; ++index){

        if(allWorkers[index]->getType() == tWorker && numberOfWorkers > 0){
            std::cout<<allWorkers[index]->getType()<<std::endl;
            workers[currentPossition] = allWorkers[index];
            currentPossition++;
            currentWorkers--;
        }
        if(allWorkers[index]->getType() == tSpecialist && numberOfSpecialists > 0){
            std::cout<<allWorkers[index]->getType()<<std::endl;
            workers[currentPossition] = allWorkers[index];
            currentPossition++;
            currentSpecialists--;
        }
        if(allWorkers[index]->getType() == tTeamLeader && numberOfTeamLeaders > 0){
            std::cout<<allWorkers[index]->getType()<<std::endl;
            workers[currentPossition] = allWorkers[index];
            currentPossition++;
            currentLeaders--;
        }
    }
}

void Director::setSecretary(Secretary const &sec){

    this->mySec = sec;
}

void Director::destroy(){

    delete [] this->workers;
}

void Director::copyFrom(Director const &other){

    this->setNumberOfSpecialists(other.numberOfSpecialists);
    this->setNumberOfTeamLeaders(other.numberOfTeamLeaders);
    this->setNumberOfWorkers(other.numberOfWorkers);
    this->addWorkers(other.workers);
    this->setSecretary(other.mySec);
    this->createdWorkers = other.createdWorkers;
}
