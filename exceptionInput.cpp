#include<iostream>
#include<stdio.h>
#include<ctype.h>

int main() {
    std::cout << "Please enter two numbers\t" ;

    try
    {
        int a;
        a = getchar();
        
        std::cout << a;
        // [](int& a){...}(<calling of the lambda function>)
        if( [](int value){ return (value==48 or value==49 or value==50); }( a ) ){
            
            try
            {
                char b;
                std::cout << "Enter B";
                while( (getchar()) !='\n');
                b = getchar();

                if( [](int value){ return (value==48 or value==49 or value==50); }( b ) ) {
                    std::cout << "Congo!! It's a valid input";
                }     
                else {
                    throw "invalid 'b'";
                }
            }
            catch(const char* error)
            {
                throw;
            }
                    
        }
        else {
            throw "invalid 'a'";
        }

    }
    catch(const char* error)
    {
        std::cout << error;
    }
    
}