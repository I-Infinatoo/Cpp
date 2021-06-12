#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'minimumNumber' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING password
 */
bool isSpecial( char ch) {
    if(ch == '!' or ch == '@' or ch == '#' or ch == '$' or ch == '%'
        or ch == '^' or ch == '&' or ch == '*' or ch == '(' or ch == ')'
        or ch == '-' or ch == '+') {
         
        return true;
    }
    return false;
}


int minimumNumber(int n, string password) {
   
   int count =0;
   bool cl = false, sl = false, num = false, sc = false;
      
   for(auto i =0; i<password.size(); i++) {
       if(!cl and password[i] >= 'A' and password[i]<='Z') {
           count+=1;
           cl = true;
       }
       if(!sl and password[i] >= 'a' and password[i]<='z') {
           count+=1;
           sl = true;
       }
       if(!num and password[i] >= '0' and password[i]<='9') {
           count+=1;
           num = true;
       }
       if(!sc and isSpecial(password[i])) {
           count+=1;
           sc = true;
       }
   }
    if(n>=6)
        return 4-count;
    else
        return (6-n) > (4-count) ? (6-n) : (4-count); 
}

int main()
{
    int n =5;
    string password = "A98#+";
    cout << minimumNumber(n, password);

}    