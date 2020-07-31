#pragma once
/* 
    Header filer for print
*/
#include<iostream>
#include<type_traits>

namespace print
{

template<typename T>
void printLine(T var);

} // namespace print

template<typename T>
void print::printLine(T var /*= std::string("Nothing to Print")*/){
        std::cout << var << std::endl;
}