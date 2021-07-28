#include<bits/stdc++.h>
using namespace std;


unsigned int findDist(int x1, int y1, int x2, int y2) {

    return ( pow( abs(x1-x2) ,2 ) + pow( abs(y1-y2) ,2 ));

}

int main () {


    int n, m;
    cin >> n; 
    int x[n];

    for(int i=0; i<n; i++) { cin >> x[i]; }   
    cin >> m;

    int y[m];
    for(int i=0; i<m; i++) { cin >> y[i]; }   

    unsigned int maxDist = UINT_MAX;
    unsigned int currentDist;

    for(int i=0; i<(n-1); i++) {
        for(int j=i+1; j<n; j++) {
            currentDist = findDist(x[i],y[i],x[j],y[j]);
            if( maxDist > currentDist ) {
                maxDist = currentDist;
            }
        }
    }

    cout << currentDist;

    return 0;
}