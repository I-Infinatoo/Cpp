#include<bits/stdc++.h>
using namespace std;


#define lui long unsigned int

bool isPalindrome(string s, int left, int right) {
    lui mid = (left+right) / 2 ;
    for(lui i = left, j = right; i< mid; i++, j--) {
        if(s[left] != s[right]){
            return false;
        }
    }
    return true;
}

int palindromeIndex(string s) {
    lui mid = s.size() / 2;
    
    for(lui i = 0, j = s.size()-1; i< mid; i++, j--) {
    
        if(s[i] != s[j]){
            if(isPalindrome(s, i+1, j)) {
                return i;
            }
            else return j;
        }
    }
    return -1;
}


int main()
{
    cout << palindromeIndex("fruits");

    return 0;
}
