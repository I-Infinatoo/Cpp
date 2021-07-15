#include<iostream>

void fun1();
void fun2();

#pragma startup fun1

void fun1() {
    std::cout << "\nIn fun1\n" ;
}

void fun2() {
    std::cout << "\nIn fun2\n" ;
}

int main() {

    std::cout << "\nIn main Function\n" ;

    return 0;
}