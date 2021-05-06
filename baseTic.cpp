#include<bits/stdc++.h>
using namespace std;

map<int, int> mp { {0,0}, {1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {6,0}, {7,0} };

void funChange(int a, int b, int c = -1, int d = -1) {

    if(a!=-1) {
        mp[a] += 1; 
    }
    if(b!=-1) {
        mp[b] += 1; 
    }
    if(c!=-1) {
        mp[c] += 1; 
    }
    if(d!=-1) {
        mp[d] += 1; 
    }

}

void disp() {
    
    for(int i=0; i<mp.size(); i++) {

        cout << i << " : " << mp[i] << "   ";

    } cout << "\n" ;
}

void check() {

    for(int i=0; i<mp.size(); i++) {
        
        if( mp[i] == 3 ) {
            cout << i ;
            break;
        }
    }

} 

int main () {

    disp();

    funChange(6, 7, 4, 1);
    funChange(3, 7, 2);
    funChange(5, 2, 6);
    funChange(2, 4);

    disp();

    check();

    return 0;
}