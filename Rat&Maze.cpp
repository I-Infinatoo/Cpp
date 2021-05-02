#include<iostream>
#include<vector>

using namespace std;
int result=0;

bool isItSafe(int i, int j, int n) {
    return i<n and i>=0 and j<n and j>=0;
}

void maze (int i, int j, int n, vector<vector<int>> &arr, vector<vector<int>> &visited) {
    if( arr[n-1][n-1]==1) {         //if end is blocked
        return;
    }

    if( i==n-1 and j==n-1 ) {       //if reached destination
        result++;
        return;
    }

    if( not isItSafe(i, j, n)) {    //if out of range
        return;
    }

    visited[i][j] = 1;

    if( isItSafe(i+1, j, n) and arr[i+1][j]==0 and visited[i+1][j]==0 ) {
        //if ready to move down
        maze(i+1, j, n, arr, visited);
    }
    if( isItSafe(i-1, j, n) and arr[i-1][j]==0 and visited[i-1][j]==0 ) {
        //if ready to move up
        maze(i-1, j, n, arr, visited);
    }
    if( isItSafe(i, j+1, n) and arr[i][j+1]==0 and visited[i][j+1]==0 ) {
        //if ready to move right
        maze(i, j+1, n, arr, visited);
    }
    if( isItSafe(i, j-1, n) and arr[i][j-1]==0 and visited[i][j-1]==0 ) {
        //if ready to move left
        maze(i, j-1, n, arr, visited);
    }

    visited[i][j] = 0;
}

int main () {

    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n, 0));
    vector<vector<int>> visited(n, vector<int>(n, 0));

    for (int i=0; i<n; i++) {
        for (int j =0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    maze(0, 0, n, arr, visited);
    cout << result << "\n";

    // for (int i=0; i<n; i++) {
    //     for (int j =0; j<n; j++) {
    //         cout << arr[i][j] << " " ;
    //     }
    //     cout << "\n" ;
    // }

    return 0;
}