#include <iostream>
#include "Worker.h"
#include "Specialist.h"
#include "Director.h"
#include "Secretary.h"
#include "TeamLeader.h"

const int MAX_LENGTH = 100;
const int EGN_LENGTH = 11;

void sortArray(Worker **emp, int allWorkers){

    for(int index = 1; index < allWorkers; ++index){

        for(int elem = 0; elem < allWorkers - index; ++elem){

            if(emp[elem + 1]->getSalary() > emp[elem]->getSalary()){

                Worker **temp = new Worker*[1];
                temp[0] = emp[elem];
                emp[elem] = emp[elem + 1];
                emp[elem + 1] = temp[0];

                delete [] temp;
            }
        }
    }
}

void requiredEmployees(Worker **emp, int allWorkers){

    std::cin.ignore();
    int requiredWorkers, requiredSpecialists, requiredLeaders;
    std::cout<<"Enter number of workers: ";
    std::cin>>requiredWorkers;
    std::cout<<"Enter number of specialists: ";
    std::cin>>requiredSpecialists;
    std::cout<<"Enter number of team leaders: ";
    std::cin>>requiredLeaders;

    int numOfWorkers = 0, numOfSpecialist = 0, numOfLeaders = 0;
    for(int index = 0; index <allWorkers; ++index){

        if(emp[index]->getType() == tWorker){
            numOfWorkers++;
        }

        else if(emp[index]->getType()== tSpecialist){
            numOfSpecialist++;
        }
        else if(emp[index]->getType() == tTeamLeader){

            numOfLeaders++;
        }
    }

    if(numOfWorkers >= requiredWorkers && numOfSpecialist >= requiredSpecialists && numOfLeaders >= requiredLeaders){

        sortArray(emp,allWorkers);
        Secretary mySec;
        Director boss(mySec,emp,numOfWorkers,numOfSpecialist, numOfLeaders, allWorkers);
        std::cout<<boss.paySalary()<<std::endl;
    }
}

Worker* createWorker(){

    std::cin.ignore();
    char choice;
    std::cout<<"What kind of employee do you want?\n"<<"(W)orker, (S)pecialist\t or (T)eam leader: ";
    std::cin>>choice;

        char name[MAX_LENGTH];
        char egn[EGN_LENGTH];
        char address[MAX_LENGTH];
        char department[MAX_LENGTH];
        char description[MAX_LENGTH];
        char departmentInformation[MAX_LENGTH];
        double salary;
        std::cin.ignore();
        std::cout<<"Enter name of employee: ";
        std::cin.getline(name,MAX_LENGTH);
        std::cout<<"Enter egn(ID): ";
        std::cin.getline(egn,EGN_LENGTH);
        std::cout<<"Enter address: ";
        std::cin.getline(address,EGN_LENGTH);
        std::cout<<"Enter department: ";
        std::cin.getline(department,EGN_LENGTH);
        std::cout<<"Enter salary: ";
        std::cin>>salary;

    switch(choice){
        case 'W':

            return new Worker(name,egn,address,department,salary);
        case 'S':

            std::cin.ignore();
            std::cout<<"Enter description: ";
            std::cin.getline(description,EGN_LENGTH);
            return new Specialist(name,egn,address,department,salary,description);
        case 'T':

            std::cin.ignore();
            std::cout<<"Enter description: ";
            std::cin.getline(description,EGN_LENGTH);
            std::cout<<"Enter department information: ";
            std::cin.getline(departmentInformation,EGN_LENGTH);
            return new TeamLeader(name,egn,address,department,salary,description,departmentInformation);

        default:
            return new Worker;
    }
}

void start(){

    int number;
    std::cout<<"Enter number of employees: ";
    std::cin>>number;

    Worker** allWorkers = new Worker*[number];
    for(int index = 0; index < number; ++index){

        allWorkers[index] = createWorker();
    }

    requiredEmployees(allWorkers,number);

    delete [] allWorkers;
}

int main()
{
    start();
    return 0;
}
