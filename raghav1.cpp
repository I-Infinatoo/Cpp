#include<bits/stdc++.h>
using namespace std;

int main () {
    int a,b,c;
    //int a = 3521 , b = 2452 , c = 1352 ;
    cin >> a >> b >>c;

    int num1 = 0;

    int r1, r2, r3;
    
    while (a!=0) {
        
        r1 = a%10;
        r2 = b%10;
        r3 = c%10;

        num1 =  num1 * 10 +  (( max(max(r1,r2),r3) ) - ( min(min(r1,r2),r3) ) ) ;
        

        a/=10;
        b/=10;
        c/=10;

    }
  
   // cout << num1;

    int reversedNumber = 0;

    while( num1 != 0 ) {
        
        reversedNumber = reversedNumber*10 + num1%10;
        num1 /= 10;
    }

    cout << reversedNumber ;

    return 0;
}