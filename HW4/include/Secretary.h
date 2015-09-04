#ifndef SECRETARY_H
#define SECRETARY_H

#include "Worker.h"


class Secretary: public Worker
{
    public:
        Secretary();
        Secretary(char*, char*, char*, char*, double, char**,size_t);
        Secretary(Secretary const &);
        Secretary& operator=(Secretary const &);

        ~Secretary();
        void setNumberOfLanguages(size_t);
        size_t getNumberOfLanguages();
        void setList(char**);
        void printList(char**);

    protected:
    private:

    size_t numberOfLanguages;
    char** list;
    void destroy();
    void copyFrom(Secretary const &other);


};

#endif // SECRETARY_H
