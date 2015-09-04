#include "Cookie.h"

Cookie::Cookie(char** n, size_t words): text(NULL) {

    this->setText(n,words);
}

Cookie::Cookie(const Cookie& c1): text(NULL){

    this->setText(c1.text,c1.numberOfWords);
}

Cookie::Cookie():text(NULL), numberOfWords(1){

    this->text = new char*[numberOfWords];
    for(size_t index = 0 ; index < numberOfWords; ++index){
       this->text[index] = new char[10];
       this->text[index][0] = '\0';
    }
}

 Cookie& Cookie::operator=(Cookie& c1){

    destroy();
    if (this != &c1){
        this->setText(c1.text,c1.numberOfWords);
    }

    return *this;
 }

Cookie::~Cookie()
{
    destroy();
}

void Cookie::destroy(){
    for(size_t index = 0; index < numberOfWords; ++index){

        delete [] this->text[index];
    }
    delete [] this->text;
}

void Cookie::setText(char** sentence,size_t words){

    this->numberOfWords = words;
    this->text = new char*[numberOfWords];
    for(size_t index = 0; index < words; ++index){

        int newSize = strlen(sentence[index]) + 1;
        this->text[index] = new char[newSize];
        strcpy(text[index],sentence[index]);
    }
}

void Cookie::getText(){

    for(size_t index = 0; index < this->numberOfWords; ++index){

        std::cout<<this->text[index]<<" ";
    }
    std::cout<<std::endl;
}

