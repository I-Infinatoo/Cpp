// find the row with max number of 1's in the sorted matrix 
#include<iostream>
#include<algorithm>
#include<vector>

int main () {
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::vector<int>>arr(n, std::vector<int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) 
            std::cin >> arr[i][j];

    // int minIdx=m;   //considering no array is having 1

    // for(int i=0; i<m; i++) {
    //     if(arr[0][i]==1){
    //         minIdx=i;
    //         break;
    //     }
    // }
    // // std::cout << minIdx << "\n";
    // int i=1, j=minIdx, ans=0;

    // while(i<n and j>=0){
        
    //     if(arr[i][j-1]==1){
    //         ans=i;
    //         j--;
    //     }

    //     i++;
    // }
    // if(j==m){ ans=-1; }

    int row=0, col=m-1, ans=-1;

    while(row < n and col>=0){
    
        if(arr[row][col]==1){
            col--;
            ans=row;
        }
        else
            row++;
    }

    std::cout << ans << "\n";

    return 0;
}