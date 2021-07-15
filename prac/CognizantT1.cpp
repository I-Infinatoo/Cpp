#include<bits/stdc++.h>
using namespace std;

bool subSequnce(string blood, string virus) {
    int k=0;

    for( char c: virus) {
        if(c == blood[k] ) {
            k++;
        }

        if( k==blood.length()) { 
            return k==blood.length();
        }
    }
    
    return k==blood.length();
}

int main (){
    
    string virus;
    cin >> virus;

    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    int t;
    cin >> t;

    while(t--) {
        string blood;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> blood;

        if( not subSequnce(blood, virus)) {
            cout << "NEGATIVE\n" ;

        } else {
            
            cout << "POSITIVE\n" ;
        }
 
    }

    return 0;
}