/**
 * 01- Unbounded Knapsack
*/

#include<bits/stdc++.h>
using namespace std;

void ff() {
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int rodCutting(vector<int>& price, int n) {
    // vector<int>length(n);
    // for(int i =0; i<n; i++){
    //     length[i] = i+1;
    // }

    int t[n+1][n+1];
    for(int i = 0, j =0; j<n+1; j++) {
        t[i][j] = 0;
    }
    for(int i = 0, j =0; i<n+1; i++) {
        t[i][j] = 0;
    }

    for(int i = 1; i<n+1; i++) {
        for(int j =1; j<n+1; j++) {

            // if(length[i-1] <= j) {
            //     t[i][j] = max(price[i-1] + t[i][j-length[i-1]], t[i-1][j]); 
            if(i <= j) {
                t[i][j] = max(price[i-1] + t[i][j-i], t[i-1][j]); 
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][n];
}

int main() {

    ff();

    int n;
    cin >> n;

    vector<int>price(n);    
    for(int i =0; i<n; i++) {
        cin >> price[i];
    }

    cout << rodCutting(price, n);
    return 0;
}