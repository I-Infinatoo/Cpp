#include<iostream>

// ch = 4

//         01234567
//    0 // 1      1
//    1 // 12    21
//    2 // 123  321
//    3 // 12344321

void printPattern1(int n){
    
    for(int i=0; i<n; i++) {

        for(int j=0; j<=i; j++)
            std::cout << j+1 ;

        for(int k=0; k<(n-1-i)*2; k++)
            std::cout << " ";
        
        for(int l=i; l>=0; l--)
            std::cout << l+1 ;
        
        std::cout << std::endl;
    }

}

int main (){

    int ch = 5;
    // std::cin >> ch;

    printPattern1(ch);

    return 0;
}