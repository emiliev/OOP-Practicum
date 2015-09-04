#include "Jar.h"

Jar::Jar(){

    this->size = 0;
    this->capacity = 2;
    this->cookies = new Cookie[capacity];
}

Jar::~Jar()
{
    del();
}

void Jar::del(){

   delete [] cookies;
}

void Jar::addCookie(Cookie biscuit){

    if(this->size >= capacity){
        extend();
    }
    this->cookies[size] = biscuit;
    this->size++;

}

void Jar::printAll(){
    for(int index = 0 ; index < this->size - 1; ++index){
        this->cookies[index].getText();
    }
}

void Jar::extend(){
    resize(this->capacity * 2);
}

void Jar::resize(int newCap){

    Cookie* newCookies = new Cookie[newCap];
    this->capacity = newCap;
    for(size_t index = 0; index < this->size; ++index){

        newCookies[index] = this->cookies[index];
    }

    delete [] this->cookies;
    cookies = newCookies;
}

void Jar::removeCookieAtIndex(size_t index){

    if(index < 0 || index >= size){

        return;
    }

     for(int i=index; i < size - 1; ++i)
    {
        cookies[i] = cookies[i + 1];
    }

    --size;

    if (size < capacity / 4)
    {
        resize(capacity/2);
    }
}
