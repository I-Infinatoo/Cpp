#include<bits/stdc++.h>
using namespace std;

int fact(int n) {
    //base case
    if(n==1) { return 1; }
    //self work and hypothesis
    return n*fact(n-1); 
}

int sumNNumbers(int n){
    //base case
    if(n==1) { return 1; }
    //self work and hypothesis
    return n + sumNNumbers(n-1);
}

int nFibo(int n) {
    //base case
    if(n==0 || n==1 ) return n;
    //selfwork & hypothesis
    return nFibo(n-1) + nFibo(n-2);
}

void nNaturalinc(int n) { // 1 2 3 4 5 6 ...
    if(n==1) { 
        cout << n << " "; 
        return; 
    }
    nNaturalinc(n-1);
    cout << n << " "; 
}

void nNaturaldec(int n) { // 6 5 4 3 2 1
    if(n==1) { 
        cout << n << " "; 
        return; 
    }
    cout << n << " "; 
    nNaturaldec(n-1);
}

void print(int n) { // n=5 --> 5 4 3 2 1 2 3 4 5
    if(n==1) { 
        cout << n << " "; 
        return; 
    }
    cout << n << " "; 
    print(n-1);
    cout << n << " "; 
}

int countBinaryLen(int n){ //number of binary strings of length 'n' having no consecutive '1'
    if(n==1 || n==0){ return n+1; }
    return countBinaryLen(n-1) + countBinaryLen(n-2);
}

int nPersonParty(int n){//number of ways in which a erson can go to a party either in pair or single
    if(n==1 || n==2) { return n;}
    return nPersonParty(n-1) + (n-1) * nPersonParty(n-2);
}

long long int power(int a, int b) {// a^b   this is an optimised approach O(log b)
    //base case
    if(b==0) return 1;
    if(b==1) return a;
    //hypothesis
    long long temp = power(a, b/2);
    //self work
    if(b%2==0) return temp*temp;//if b is even
    else return a*temp*temp; //if b is odd
} 

int main() {

    cout << power(2,3);
    return 0;
}