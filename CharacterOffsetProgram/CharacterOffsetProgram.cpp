// CharacterOffsetProgram.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Joseph Blommel
// CIS 1202
// 11/30/2021

#include <iostream>
#include <stdexcept>
#include <exception>

char character(int, char);

struct invalidCharacterException : public std::exception {
    const char * what() const throw () {
        return "Invalid character exception thrown.";
    }
};

struct invalidRangeException : public std::exception {
    const char * what() const throw () {
        return "Invalid range exception thrown.";
    }
};
int main()
{
    try {
        //std::cout << character(1, 'a') << std::endl;
        //std::cout << character(-1, 'a') << std::endl;
        //std::cout << character(-1, 'Z') << std::endl;
        //std::cout << character(5, '?') << std::endl;
        std::cout << character(-25, 'z');
        //std::cout << character(32, 'A') << std::endl;
   }
    catch (invalidRangeException invalid){
        std::cout << invalid.what() << std::endl;
    }
    catch (invalidCharacterException charex) {
        std::cout << charex.what() << std::endl;
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
    //std::cout << (int)'z' << std::endl; //122
    //std::cout << (int)'a' << std::endl; //97
    //std::cout << (int)'Z' << std::endl; //90
    //std::cout << (int)'A' << std::endl; //65

}

char character(int offset, char start) {
    
    if ((start < 'a' || start > 'z') && (start < 'A' || start > 'Z')) {
        throw invalidCharacterException();
        }

    if (offset < -25 || offset > 25) {
        throw invalidRangeException();
    }
        
    int newChar = offset + (int)start;

    if ((newChar < 97 || newChar > 122) && (newChar < 65 || newChar > 90)) {
        throw invalidRangeException();
    }
        return (char)newChar;
}

