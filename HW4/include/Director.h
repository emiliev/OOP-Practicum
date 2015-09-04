#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <iostream>
#include "Secretary.h"
#include "Worker.h"

class Director
{
    public:
        Director();
        Director(Secretary &, Worker **, size_t,size_t,size_t, int);
        Director(Director const &);
        Director& operator=(Director const &);
        ~Director();

        void setSecretary(Secretary const &);
        void setNumberOfWorkers(size_t);
        void setNumberOfTeamLeaders(size_t);
        void setNumberOfSpecialists(size_t);

        size_t getNumberOfWorkers();
        size_t getNumberOfTeamLeaders();
        size_t getNumberOfSpecialists();

        double paySalary();
        void showAllWorkers();
    protected:
    private:
    Worker** workers;
    Secretary mySec;
    size_t numberOfWorkers;
    size_t numberOfSpecialists;
    size_t numberOfTeamLeaders;
    int createdWorkers;

    void addWorkers(Worker**);
    void destroy();
    void copyFrom(Director const &);
};

#endif // DIRECTOR_H
