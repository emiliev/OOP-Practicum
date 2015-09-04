#ifndef WORKER_H
#define WORKER_H

#include <string.h>
#include <iostream>
enum workerType{tWorker,tSpecialist, tTeamLeader};

class Worker
{
    public:
        Worker();
        Worker(Worker const &);
        Worker(char*,char*,char*,char*,double);
        Worker& operator=(Worker const &);
        ~Worker();

        void setName(char*);
        void setEgn(char*);
        void setAddress(char*);
        void setDepartment(char*);
        void setSalary(double);

        char* getName();
        char* getEgn();
        char* getAddress();
        char* getDepartment();
        double getSalary();

        workerType getType();
        void copyFrom(Worker const &);
    protected:
        workerType type;
    private:

        char* name;
        char* egn;
        char* address;
        char* department;
        double salary;

        void destroy();
};

#endif // WORKER_H
