#include<bits/stdc++.h>
using namespace std;

/*

5
5 5
2 7 
8 10
10 20
4 5

*/

bool isPrime(int n) {

    if (n <= 1)
        return false;
    
    if (n <= 3)
        return true;
    
    if (n % 2 == 0 || n % 3 == 0)
        return false;
  
    for (int i = 5; i * i <= n; i = i + 6){
        
        if (n % i == 0 || n % (i + 2) == 0) { 
            return false;
        }
    }
    return true;
}

int main () {

    int t;
    cin >> t;

    while (t--){
        int num1, num2, minNumber = 0 , maxNumber;
        bool flag1 = false, flag2 = false ;
        cin >> num1 >> num2;

        int midRange = (num1+num2) /2;
        for(int i=num1; i<= midRange; i++) {
            
            if(isPrime(i) == true ) {
                minNumber = i;
                flag1 = true;
                break;
            }
        }

        for(int i=num2; i > midRange; i--) {
            
            if(isPrime(i) == true ) {
                maxNumber = i;
                flag2 = true;
                break;
            }
        }
        
        
        if(flag1 == false && flag2 == false) {
            return -1;
        
        } else if (flag1 == false || flag2 == false) {
            
            return 0;

        } else {

            return (maxNumber-minNumber);
        }
    }

    return 0;
}