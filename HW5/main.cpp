#include <iostream>
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Group.h"
#include <fstream>
#include <string.h>
using namespace std;


Shape* shape(ifstream &input, char* buffer){

    if(strcmp(buffer,"circle") == 0){

        double x1,y1,radius;
        input>>radius>>x1>>y1;
        return new Circle(radius,x1,y1);
    }
    else if(strcmp(buffer,"triangle") == 0){

        double x1,y1,x2,y2,x3,y3;
        input>>x1>>y1>>x2>>y2>>x3>>y3;
        return new Triangle(x1,y1,x2,y2,x3,y3);
    }
    else {

        double x1,y1,x2,y2;
        input>>x1>>x2>>y1>>y2;
        return new Rectangle(x1,x2,y1,y2);
    }

}

int main()
{
    std::cout<<"hello worldasdasd\n";
    ifstream input("information.txt");
    if(input){

        char buffer[12];
        while(!input.eof()){

            input>>buffer;
            if (!input.eof()) {

                if(strcmp(buffer,"group") == 0){
                    std::cout<<"Entered group\n";
                    double x1,y1;
                    char text[4];
                    input>>text;
                    input>>x1>>y1;
                    Group gr1(x1,y1);
                    input>>buffer;
                    while(!strcmp(buffer, "group") == 0){

                        Shape *shape1 = shape(input,buffer);
                        gr1.addShape(shape1);
                        input>>buffer;
                    }
                    gr1.translation();
                    input>>text;
                    input>>buffer;
                    std::cout<<"Left group\n";
                }
                Shape *shape1 = shape(input,buffer);
                shape1->returnCoordinates();
                shape1->isContaining(10,15);
                }
            }
    }
    input.close();

    return 0;
}
