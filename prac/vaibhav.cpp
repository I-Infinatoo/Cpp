#include<bits/stdc++.h>
using namespace std;

int findkey(int input1, int input2, int input3 ){

    input1=input1/100;
    input1=input1%10; //got the hundred digit of input1

    input2=input2/10;
    input2=input2%10; //got the tens digit of input2

    int max=0;
    while(input3){
        //max = std::max(max, input3%10);
        if(input3%10 > max) {
            max=input3%10;
        }
        
        input3/=10;
    }

    return input1*input2*max;
}

int main() {

    cout << findkey(3521, 2452, 1352);

  return 0;  
} 
