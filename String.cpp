// String.cpp
//
// ICS 46 Winter 2022
// Project #0: Getting to Know the ICS 46 VM
//
// Implement all of your String member functions in this file.
//
// Note that the entire standard library -- both the C Standard
// Library and the C++ Standard Library -- is off-limits for this
// task, as the goal is to exercise your low-level implementation
// skills (pointers, memory management, and so on).

#include "String.hpp"
#include "OutOfBoundsException.hpp"

String::String(){
   mainString = new char[0];
   lengthString = 0;
}

String::String(const char* chars)
{

    unsigned i = 0;
    while (chars[i] != '\0'){
       ++i;
    }

    lengthString = i;
    mainString = new char[lengthString];
    
    char* bob = new char[lengthString];
    for (unsigned i = 0; i < lengthString; i++){
        bob[i] = chars[i];
    }

    mainString = bob;     

}

String::String(const String& s){
    unsigned int newL = s.lengthString;

    char* bob = new char[s.lengthString];

    for (unsigned i = 0; i < newL; i++){
        bob[i] = s.mainString[i];
    } 

    mainString = bob;
    lengthString = newL;
}

String::~String() noexcept{
    delete[] mainString;
} 

String& String::operator=(const String& s){


    lengthString = s.lengthString;

    char* bob = new char[lengthString];

    for (int i=0; i < lengthString; i++)
        bob[i] = s.mainString[i];

    mainString = bob;

    return *this;
}

void String::append(const String& s){

    char* bob = new char[lengthString + s.lengthString];
    unsigned int tim = lengthString + s.lengthString;

    for (unsigned i = 0; i < lengthString; ++i){
        bob[i] = mainString[i];
    }
    for (unsigned i = 0; i < s.lengthString; ++i){
        bob[i + lengthString] = s.mainString[i];
    }

    mainString = bob;   
    lengthString = tim;

}


char String::at(unsigned int index) const{
    
    if (index >= lengthString)
    {
        throw OutOfBoundsException();
    }

    return mainString[index];

}
char& String::at(unsigned int index){
    if (index >= lengthString)
    {
        throw OutOfBoundsException();
    }

    char& bob = mainString[index];

    return bob;
    
}

void String::clear(){
    char* bob = new char[0];
    mainString = bob;
    lengthString = 0;
}

int String::compareTo(const String& s) const noexcept{
    
    if (mainString == s.mainString)
    {
        return 0;
    }
    
    for (int i = 0; i < lengthString; ++i){
        if (mainString[i] != s.mainString[i]){
            if (mainString[i] < s.mainString[i])
            {
                return -1;
            }else{
                return 2;
            }
        }
    }

    return 0;

}

String String::concatenate(const String& s) const{

    char* bob = new char[lengthString + s.lengthString];

    for (unsigned i = 0; i < lengthString; ++i){
        bob[i] = mainString[i];
    }
    for (unsigned i = 0; i < s.lengthString; ++i){
        bob[i + lengthString] = s.mainString[i];
    }

    return String(bob);

}

bool String::contains(const String& substring) const noexcept{

    if (mainString == substring.mainString) {
        return true;
    }

    bool JIM = true;
    const char* kk = substring.mainString;

    for (int i = 0; i < lengthString - substring.lengthString; ++i){
        char* bob = new char[substring.lengthString];
        int tim = 0;
        for (int j = i; j < i + substring.lengthString; ++j){
            bob[tim] = mainString[j];
            tim++;
        }
        while (*bob != '\0'){
            if (*kk != *bob){
                JIM = false;
                break;
            }
            kk++;
            bob++;
        }
        if (JIM){
            return true;
        }
        JIM = true;
    }
    return false;
    
}

bool String::equals(const String& s) const noexcept{

    char* bob = mainString;
    char* tim = s.mainString;

    if (lengthString != s.lengthString){
        return false;
    }
    

    while (*bob != '\0'){
        if (*bob != *tim){
            return false;
        }
        tim++;
        bob++;
    }
    return true;
}

int String::find(const String& substring) const noexcept{

    if (mainString == substring.mainString) {
        return true;
    }

    bool JIM = true;
    const char* kk = substring.mainString;

    for (int i = 0; i < lengthString - substring.lengthString; ++i){
        char* bob = new char[substring.lengthString];
        int tim = 0;
        for (int j = i; j < i + substring.lengthString; ++j){
            bob[tim] = mainString[j];
            tim++;
        }
        while (*bob != '\0'){
            if (*kk != *bob){
                JIM = false;
                break;
            }
            kk++;
            bob++;
        }
        if (JIM){
            return i;
        }
        JIM = true;
        delete[] bob;
    }
    return -1;
}

bool String::isEmpty() const noexcept{
    return lengthString == 0 ? true : false;
}

unsigned int String::length() const noexcept{
    return lengthString;
}

String String::substring(unsigned int startIndex, unsigned int endIndex) const{

    if (endIndex >= lengthString)
    {
        throw OutOfBoundsException();
    }
    char* newArr = new char[endIndex - startIndex];
    const char* returnNewString;

    for (int i = 0; i < endIndex - startIndex; ++i){
        newArr[i] = mainString[i + startIndex];
    }

    returnNewString = newArr;
    return String(returnNewString);
}

const char* String::toChars() const noexcept{
    return mainString;
}
