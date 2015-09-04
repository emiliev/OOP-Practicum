#ifndef SPECIALIST_H
#define SPECIALIST_H

#include "Worker.h"
#include <iostream>
class Specialist: public Worker
{
    public:
        Specialist();
        Specialist(char*,char*,char*,char*,double,char*);
        Specialist(Specialist const &);
        Specialist& operator=(Specialist const &);
        ~Specialist();

        void setDescription(char*);
        char* getDescription();

        void copyFrom(Specialist const &);

    protected:
    private:

    void destroy();
    char* description;
};

#endif // SPECIALIST_H
