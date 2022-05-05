#include<bits/stdc++.h>
using namespace std;

#define ll long long int

void ff() {
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void  subSetSum(vector<int>& arr, int n, int sum, vector<vector<bool>>& t) {
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
}


int minSSetSumDiff(vector<int>& arr, int n) {
  int sum = 0;
        for(int i =0; i<n; i++) {
            sum += arr[i];
        }

    vector<vector<bool>>t(n+1, vector<bool>(sum+1));
        // bool t[n+1][sum+1];

        subSetSum(arr, n, sum, t);
        // vector<int>ans;

        int ans=INT_MAX;
	    for(int i=0;i<=(sum/2);i++)
	        if(t[n][i])
	            ans=min(ans,sum-2*i);
	    return ans;

}


int main() {

    ff();

    int n;
    cin >> n;

    vector<int>arr(n);

    for(int i =0; i<n; i++) {
        cin >> arr[i];
    }

    cout << minSSetSumDiff(arr, n);

    return 0;
}