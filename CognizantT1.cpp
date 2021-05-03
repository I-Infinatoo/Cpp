#include<bits/stdc++.h>
using namespace std;

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

        bool flag = false;
        
        if(blood.length() == 1 ) {
        
            if(virus.find_first_of(blood[0]) == -1 ) {
                //if single element is not present
                flag = true;
            
            } else{
                //if single element is present
                flag = false;
            }           
        
        } else{

            for(int i =1; i<(blood.length()); i++) {

                if(virus.find_first_of(blood[i]) > virus.find_first_of(blood[i-1]) ) {
                    
                } else {
                    flag = true;
                    break;
                }
            }
        
        }

        if( flag == true) {
            cout << "NEGATIVE\n" ;

        } else {
            
            cout << "POSITIVE\n" ;
        }

        //cout << "\t" << blood << "\t" ; 
    }

    return 0;
}