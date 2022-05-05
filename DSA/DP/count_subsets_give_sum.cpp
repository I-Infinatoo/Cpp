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

 int perfect(vector<int>& arr, int n, int sum, vector<vector<int>>& t)
	{
	    
	    if(n==0 && sum==0)
	        return 1;
	    
	    if(n<=0 || sum<0)
	        return 0;
	    if(t[n][sum] != -1) {
	        return t[n][sum];
	    }
	    return t[n][sum] = ((perfect(arr, n-1, sum-arr[n-1], t)) % (1000000007) + 
	                            (perfect(arr,n-1,sum, t)) % (1000000007)) % (1000000007);
	}
	int perfectSum(vector<int>& arr, int n, int sum)
	{
       
        vector<vector<int>>t(n+1,vector<int>(sum+1,-1));
        return perfect(arr, n, sum, t)%1000000007;
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

    cout << perfectSum(arr, n, sum);

    return 0;
}