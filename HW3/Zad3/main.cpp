#include <iostream>
#include "Vector.h"
#include "BoolVector.h"


using namespace std;

const double number = 2.2;

int main()
{

    Vector v1(3);
    cout<<"Chosen element: "<<v1[1]<<endl;
    v1.printVector();
    Vector v2(2);

    Vector v3;
    v3.printVector();

    v3 = v1 + v2 ;
    v3.printVector();
    cout<<"asdsad"<<endl;
  /*  v3.printVector();

    cout<<"Original vector: ";
    v1.printVector();
    v1 = v1 + v2;
    cout<<"Add: ";
    v1.printVector();

    v1 = v1 - v2;
    cout<<"Subtract: ";
    v1.printVector();

    v1 +=v2;
    cout<<"Add: ";
    v1.printVector();

    v1 -=v2;
    cout<<"Subtract: ";
    v1.printVector();

    v1 = v1 * number;
    cout<<"Multiply: ";
    v1.printVector();

    v1 = v1 / number;
    cout<<"Divide: ";
    v1.printVector();

    v1 *= number;
    cout<<"Multiply: ";
    v1.printVector();

    v1 /= number;
    cout<<"Divide: ";
    v1.printVector();

    cout<<"Scalar product: ";
    cout<<v1%v2<<endl;

    v1 = v2;
    cout<<"Copy: ";
    v1.printVector();

    BoolVector boolV;
    boolV.printArray();
    std::cout<<boolV[1]<<std::endl;

    boolV.set(5);
    boolV.printArray();

    boolV.clear(5);
    boolV.printArray();

    cout<<sizeof(boolV)<<endl;*/
    return 0;
}
