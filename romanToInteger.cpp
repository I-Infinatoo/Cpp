#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s) {
        unordered_map<char,int> mp = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int n = s.length(),sum = 0;
        for(int i=0;i<n;++i)
        {
            if(i+1<n && mp[s[i]]<mp[s[i+1]])
            {
                sum+=mp[s[i+1]]-mp[s[i]];
                i++;
            }
            else 
                sum+=mp[s[i]];
        }
        return sum;
    }


int main()
{
    cout << romanToInt("MDCCCLXXXIV");

    return 0;
}
