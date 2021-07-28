// Templates instructs compiler to write defination when the function or part of that program w/c is using 
// template gets called in the program.
#include<iostream>
#include<string>

template <typename T>
void Print(T value ) {
    std::cout << value << std::endl ;
}


int main () {

    Print(5);
    Print(5.5f);
    Print("Ishu");

    return 0;
}