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

// recurssion
/*
bool equalSumPartition(vector<int>& arr, int n, int sum) {
    if(n==0 && sum!=0) {
        return false;
    }
    if(sum == 0) {
        return true;
    }

    if(arr[n-1] <= sum) {
        return equalSumPartition(arr, n-1, sum-arr[n-1]) || equalSumPartition(arr, n-1, sum);
    } else {
        return equalSumPartition(arr, n-1, sum);
    }
}
*/

//dp
bool equalSumPartition(vector<int>& arr, int n, long long sum) {
    long long t[n+1][sum+1];

    for(int j = 1; j<sum+1; j++) {
        t[0][j] = false;
    }
    for(int i = 0; i<n+1; i++) {
        t[i][0] = true;
    }

    for(int i =1; i<n+1; i++) {
        for(int j =1; j<sum+1; j++) {

            if(arr[i-1] <= j) {
                t[i][j] = (t[i-1][j-arr[i-1]] || t[i-1][j]);
            } else {
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

    long long sum =0;

    for(int i = 0; i<n; i++) {
        sum+= arr[i];
    }
    cout << sum << "\n";
    if(sum%2!=0) {
        // cout << subSetProb(arr, n, sum/2);
        cout << "0" ;
    } else {
        cout << equalSumPartition(arr, n, sum/2);
    }
    // cout << (sum%2==0) ? equalSumPartition(arr, n, sum/2) : 0;

    return 0;
}