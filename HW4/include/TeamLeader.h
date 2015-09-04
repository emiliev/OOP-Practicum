#ifndef TEAMLEADER_H
#define TEAMLEADER_H

#include "Specialist.h"

class TeamLeader: public Specialist
{
    public:
        TeamLeader();
        TeamLeader(char* ,char* ,char* , char*, double, char*, char*);
        TeamLeader(TeamLeader const &);
        TeamLeader& operator=(TeamLeader const &);
        ~TeamLeader();

        void setDepartmentInformation(char*);
        char* getDepartmentInformation();
        void addWorkers(Worker **, int );
        void printMembers();

    protected:
    private:

    void destroy();
    char* departmentInformation;
    Worker **team;
    int members;
    void resizeTeam(int);
    void copyFrom(TeamLeader const &);

};

#endif // TEAMLEADER_H
