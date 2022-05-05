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

//recursion
/*
bool subSetProb(vector<int>& arr, int n, int sum) {
    if(n==0 && sum!=0) {
        return false;
    }

    if(sum == 0) {
        return true;
    }

    if(arr[n-1] <= sum) {
        return subSetProb(arr, n-1, sum-arr[n-1]) || subSetProb(arr, n-1, sum);
    }else {
        return subSetProb(arr, n-1, sum);
    }

}
*/

bool subSetProb(vector<int>& arr, int n, int sum) {
    
    bool t[n+1][sum+1];

    for(int i = 0; i<n+1; i++) {
        t[i][0] = true;
    }
    for(int j = 1; j<sum+1; j++) {
        t[0][j] = false;
    }

    // for(int i = 0; i < n+1; i++) {
    //     for(int j = 0; j<sum+1; j++) {
    //         cout << t[i][j]<< " ";
    //     } cout << "\n";
    // }


    for(int i = 1; i<n+1; i++) {
        for(int j = 1; j<sum+1; j++) {
    
            if(arr[i-1] <= j) {
                t[i][j] = (t[i-1][ j-arr[i-1] ] || t[i-1][j]);
            }else {
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][sum];
}

int main() {

    ff();

    int n;
    cin >> n;

    vector<int>arr(n);
    for(int i =0; i<n; i++) {
        cin >> arr[i];
    }

    int sum;
    cin >> sum;

    cout << subSetProb(arr, n, sum);
    return 0;
}