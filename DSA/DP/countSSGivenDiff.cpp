// Count the number of subset with a given sum
#include <bits/stdc++.h>
using namespace std;

void ff()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}


// int perfect(vector<int>& arr, int n, int sum, vector<vector<int>>& t) {
	    
// 	if((n==0 && sum==0) || sum == 0)
// 	    return 1;
	    
// 	if(n<=0 || sum<0)
// 	    return 0;
//     // if(n>0 && sum==0) {
//     //     return 1;
//     // }
// 	if(t[n][sum] != -1) {
// 	    return t[n][sum];
// 	}
// 	return t[n][sum] = ((perfect(arr, n-1, sum-arr[n-1], t)) % (1000000007) + 
// 	                    (perfect(arr,n-1,sum, t)) % (1000000007)) % (1000000007);
// 	}
	
// int perfectSum(vector<int>& arr, int n, int sum) {
       
//     vector<vector<int>>t(n+1,vector<int>(sum+1,-1));
//     return perfect(arr, n, sum, t)%1000000007;
// }

int subsetCount(vector<int>& nums, int n, int s1){
        // int n = nums.size();
        int t[n+1][s1+1];
        t[0][0] = 1;
        for(int i=1;i<s1+1;i++)
            t[0][i] = 0;
        for(int i=1;i<n+1;i++)
            for(int j=0;j<s1+1;j++){
                if(nums[i-1] > j)
                    t[i][j] = t[i-1][j];
                else
                    t[i][j] = t[i-1][j] + t[i-1][j-nums[i-1]];
            }
        
        return t[n][s1];
}


int countSSGivenDiff(vector<int> &arr, int n, int diff)
{
    int sum = 0;
    for (int it : arr)
    {
        sum += it;
    }

    int s1 = diff + (sum - diff) / 2;
    if (abs(diff) > sum || (sum + diff) % 2 != 0){ 
        return 0;
    }
    // cout << s1 << "\n";
    // return perfectSum(arr, n, s1);
    return subsetCount(arr, n, s1);
}

int main()
{

    ff();

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int diff;
    cin >> diff;

    cout << countSSGivenDiff(arr, n, diff);

    return 0;
}