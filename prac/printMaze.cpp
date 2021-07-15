#include<bits/stdc++.h>
using namespace std;

int main () {
    int n =5;
    vector<vector<char>> arr(n, vector<char>(n, ' '));

    arr[0][1] = arr[0][3] = arr[2][1] = arr[2][3] = arr[4][1] = arr[4][3] = '|'; 
    arr[1][0] = arr[1][2] = arr[1][4] = arr[3][0] = arr[3][2] = arr[3][4] = '_';
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n" ;
    }

    return 0;
}