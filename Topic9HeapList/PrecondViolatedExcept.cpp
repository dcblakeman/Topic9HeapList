#include "PrecondViolatedExcept.h"
//Daniel Blakeman
//CIS 2207 502
//03-28-2022
//Write a program that maintains a database containing data, Name and Birthday of your friends and relatives.  
//You will be able to enter, remove, modify or search this data.  Initially, you can assume that the names are unique.  
//The program will be able to save and load the data in a file for use later.

PrecondViolatedExcept::PrecondViolatedExcept(const std::string& message) : std::logic_error("Precondition Violated Exception: " + message)
{
}
