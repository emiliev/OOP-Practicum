#include <iostream>
#include <fstream>
#include <string.h>
#include "../Cookie.h"
#include "Jar.h"
using namespace std;

const int wordLength = 10;
const int numberOfWordsInCookie = 1;
const int numberOfCookies = 4;

void allocate(char**& buffer){

    buffer = new char*[numberOfWordsInCookie];
    for(int index = 0 ; index  <numberOfWordsInCookie; ++index){
        buffer[index] = new char[wordLength];
    }
}

void deallocate(char**& buffer){

    for(int index = 0; index < numberOfWordsInCookie; ++index){

        delete [] buffer[index];
    }
    delete [] buffer;
}

int main()
{
    Jar jar1;
    int counter = 0;
    ofstream inFile("cookiesInput", ios::binary);
    while(counter < numberOfCookies){

        char** buffer ;
        allocate(buffer);

        for(int index = 0; index <numberOfWordsInCookie; ++index){

            cin.getline(buffer[index],wordLength);
            int sizeOfWord = strlen(buffer[index]);
            inFile.write((char*)&sizeOfWord,sizeof(int));
            inFile.write(buffer[index],strlen(buffer[index]));
        }

        counter++;
        deallocate(buffer);
    }
    inFile.close();

    ifstream outputFile("cookiesInput", ios::binary);
    while(!outputFile.eof()){
        char** buffer;
        allocate(buffer);
            for(int index = 0; index <numberOfWordsInCookie; ++index){

                int lengthOfWord ;
                outputFile.read((char*)&lengthOfWord,sizeof(int));
                outputFile.read(buffer[index],lengthOfWord);
            }
            Cookie cookie1(buffer,numberOfWordsInCookie);
            jar1.addCookie(cookie1);

            deallocate(buffer);
    }

    outputFile.close();
    std::cout<<"\nAll cookies in jar: \n";
    jar1.printAll();
    jar1.removeCookieAtIndex(0);

    std::cout<<"\nRemaining cookies in jar: \n";
    jar1.printAll();


    return 0;
}
