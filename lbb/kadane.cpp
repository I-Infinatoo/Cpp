// to find max. sum of continuous sub array

#include<iostream>
#include<limits.h>
// -----------------------------------------------------------------------------------------------
// this is the traditional kedan's algo and will not work for -ve array
// eg. : -2 -3 -4 -2 -2 -1 -5 -3
// for this array the o/p produced is 0 where as o/p should be -1(max sub array sum)

// int main(){

//     int n ;
//     std::cin >> n;

//     int arr[n];
//     for(int i=0; i<n; i++) { std::cin >> arr[i]; }

//     int maxTillNow=0, current=0;

//     for(int i=0; i<n; i++){
        
//         current += arr[i];
        
//         if(current<0){
//             current=0;
//         }

//         maxTillNow = std::max(current, maxTillNow);
//     }
//     std::cout << maxTillNow << "\n";

//     return 0;    
// }

// ------------------------------------------------------------------------------------------------

// the slight change is working for the -ve array also
// -2 -3 -4 -2 -2 -1 -5 -3
// ------------------------------------------------------------------------------------------------
int main() {

    int n;
    std::cin >> n;

    int arr[n];
    for(int i=0; i<n; i++) { std::cin >> arr[i]; }

    int maxSoFar=INT_MIN, maxEndingHere=0;

    for(int i=0; i<n; i++){
        maxEndingHere += arr[i];

        maxEndingHere = std::max(maxEndingHere, arr[i]);
        // if(maxEndingHere < arr[i]){
        //     maxEndingHere = arr[i];
        // }

        maxSoFar = std::max(maxSoFar, maxEndingHere);
        // if(maxEndingHere > maxSoFar){
        //     maxSoFar = maxEndingHere;
        // }
    }

    std::cout << maxSoFar << "\n";

    return 0;
}