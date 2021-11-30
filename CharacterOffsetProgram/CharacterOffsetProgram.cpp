// CharacterOffsetProgram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdexcept>
#include <exception>

char character(int, char);

struct invalidCharacterException : public std::exception {
    const char * what() const throw () {
        return "Invalid character";
    }
};

struct invalidRangeException : public std::exception {
    const char * what() const throw () {
        return "Invalid offset";
    }
};
int main()
{
    try {
        std::cout << character(32, 'A') << std::endl;
   }
    catch (std::out_of_range outOfRange){
        std::cout << outOfRange.what();
    }
    
    std::cout << (int)'z' << std::endl;
    std::cout << (int)'a' << std::endl;
    std::cout << (int)'Z' << std::endl;
    std::cout << (int)'A' << std::endl;

}

char character(int offset, char start) {

    if (offset < 0 || offset > 25) {
        throw std::out_of_range("Character Offset is out of range");
        }

    if ((int)start < 65 || (int)start > 90)
    {
        throw std::out_of_range("Starting Character is out of range");
    }
        
    int newChar = offset + (int)start;
        return (char)newChar;
}

