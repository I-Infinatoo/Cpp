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



bool parti_K_equalSum_subset(vector<int>& arr, int i, int subsetSum, int k, vector<bool>& used, int target) {

    if(k==0) {
        return true;
    }
    if(subsetSum == target) {
        return parti_K_equalSum_subset(arr, 0, 0, k-1, used, target);
    }

    for(int i =0; i<arr.size(); i++) {
        if(used[i] || subsetSum + arr[i] > target) {
            continue;
        }

        used[i] = true;
        if ( parti_K_equalSum_subset(arr, i+1, subsetSum+arr[i], k, used, target) ) {
            return true;
        }
        used[i] = false;
    }

    return false;
}

/*
int countsubsetsum(vector<int> arr, int n, int sum){
    
    int dp[n+1][sum+1];
    
    for(int i=1;i<sum+1;i++) dp[0][i]=0;
        
    for(int i=0;i<n+1;i++) dp[i][0]=1;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(arr[i-1]<=j){
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}
    
    bool isKPartitionPossible(vector<int> arr, int n, int k)
    {
        //Your code here
        sort(arr.begin(), arr.end());

        int sum=0;
        
        for(int i=0; i<n; i++) sum += arr[i];
        
        int val = sum/k;

        if(sum%k != 0 || arr[n-1]>val)
            return false;

        int count = countsubsetsum(arr, n, val);
        if(count < k)

            return false;
        
        return true;
    }

*/
int main() {

    ff();

    int n;
    cin >> n;

    vector<int>arr(n);
    for(int i =0; i<n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    long long sum = 0;
    for(int it: arr) {
        sum+=it;
    }

    int target = sum/k;
    vector<bool>used(n, false);

    // cout << isKPartitionPossible(arr, n, k);
    cout << parti_K_equalSum_subset(arr, 0, 0, k, used, target);
    return 0;
}