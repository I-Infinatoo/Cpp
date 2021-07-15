//1 will denote the on path
#include<iostream>
#include<vector>

using namespace std;

bool isItSafe(int i, int j, int n, vector<vector<int>> &arr) {
    return i<n and i>=0 and j<n and j>=0 and arr[i][j]==1;
}

bool maze(int i, int j, int n, vector<vector<int>> &arr, vector<vector<int>> &visited) {

    if(i==n-1 and j==n-1){
        visited[i][j] == 1;
        return true;
    }

    if(isItSafe(i, j, n, arr)){

        visited[i][j] = 1;
        if( maze(i+1, j, n, arr, visited)) {
            return true;
        }
        if( maze(i, j+1, n, arr, visited)) {
            return true;
        }

        visited[i][j] = 0;
        return false;
    }

    return false;
}


int main () {
    
    int n ;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n, 0));
    vector<vector<int>> visited(n, vector<int>(n, 0));

    for ( int i =0; i<n; i++) {
        for ( int j =0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "\n" ;

    if(maze(0, 0, n, arr, visited)) {

        for ( int i =0; i<n; i++) {
            for ( int j =0; j<n; j++) {

                cout << visited[i][j] << " ";
            
            } cout << "\n" ;
        }   
    }

    return 0;
}