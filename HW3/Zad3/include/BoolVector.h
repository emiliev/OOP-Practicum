#ifndef BOOLVECTOR_H
#define BOOLVECTOR_H

#include <iostream>

class BoolVector
{
    public:
        BoolVector();
        ~BoolVector();

        void printArray();
        bool set(int index);
        bool clear(int index);
        bool operator[](int index);
    protected:
    private:
    bool boolArray[32];
    bool isValid(int index);

};

#endif // BOOLVECTOR_H
