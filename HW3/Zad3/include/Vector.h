#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector
{
    public:
        Vector();
        Vector(int n);
        Vector(const Vector& other);
        ~Vector();

        int getLength();
        void printVector();

        double operator[](int index);
        Vector operator=   ( Vector& otherV);
        Vector operator+   (Vector& );
        Vector& operator+=  (Vector& leftVector);
        Vector& operator-   (Vector& otherV);
        Vector& operator-=  (Vector& otherV);
        Vector& operator*   (double digit);
        Vector& operator*=  (double digit);
        Vector& operator/   (double digit);
        Vector& operator/=  (double digit);
        double operator%    (Vector& otherV);

    protected:
    private:
    double* a;
    int length;
    void compareLength(Vector& otherV);
    void setLength(int num);
    void resizeArray(Vector& otherV, int newLength);
    void setA(int num);
};

#endif // VECTOR_H
