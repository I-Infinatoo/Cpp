#include <bits/stdc++.h>
using namespace std;

void ff()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
}

//recursive
/*
int knapsack(vector<int> &wt, vector<int> &val, int weight, int n)
{
    if (n == 0 || weight == 0)
    {
        return 0;
    }

    if(wt[n-1] <= weight) {
        return max(val[n-1] + knapsack(wt, val, weight-wt[n-1], n-1) , knapsack(wt, val, weight, n-1)); 
    } else {
        return knapsack(wt, val, weight, n-1);
    }
}
*/

//memoization
/*
int t[10][10];
//t[n][w] : considering constraints for n <= 100, w <= 1000
int knapsack(vector<int>& wt, vector<int>& val, int weight, int n)
{
    if (t[n][weight] != -1)
    {
        return t[n][weight];
    }
    
    if(n==0 || weight ==0) {
        return 0;
    }

    if(wt[n-1] <= weight) {
        return t[n][weight] = max(val[n-1] + knapsack(wt, val, weight-wt[n-1], n-1) , knapsack(wt, val, weight, n-1)); 
    } else {
        return t[n][weight] = knapsack(wt, val, weight, n-1);
    }
}
*/

//dynamic programing
int knapsack(vector<int> &wt, vector<int> &val, int weight, int n){
    int t[n+1][weight+1];
    for(int i = 0; i<n+1; i++){
        t[i][0] = 0;
    }
    for(int j = 0; j<weight+1; j++) {
        t[0][j] = 0;
    }

    for(int i = 1; i<n+1; i++) {
        for(int j = 1; j<weight+1; j++) {
            
            if(wt[i-1] <= j) {
                t[i][j] = max(val[i-1] + t[i-1][j- wt[i-1] ], t[i-1][j]);
            }else {
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][weight];
}


int main()
{

    ff();

    // initializin the matrix
    /*
     * memset(t, -1, sizeof(t));
    */
    
    int n;
    cin >> n;

    vector<int> wt(n);
    vector<int> val(n);

    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    int weight;
    cin >> weight;

    // sort(wt.begin(), wt.end());
    // sort(val.begin(), val.end());

    // for(int i = 0; i < 10; i++) {
    //     for(int j =0; j<10; j++) {
    //         cout << t[i][j]<< " ";
    //     } cout << "\n";
    // }

    cout << knapsack(wt, val, weight, n);

    return 0;
}
