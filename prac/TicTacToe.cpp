#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;


class TicTacToe {
    
    protected:                //data members

    int n = 5;
    map <int, int> mp;     //it will decide the result 
    
    TicTacToe() {           
        //initialize with zero score
        mp = { {0,0}, {1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {6,0}, {7,0} };
    }

};  

class DispMaze : public TicTacToe {

    // protected:

    // vector<vector<char>> visited( n, vector<char>(n, ' '));
    
    //     vector<vector<char>> maze(n, vector<char>(n, ' '));
    public:
    
    DispMaze() {

        vector<vector<char>> visited( n, vector<char>(n, ' '));
    
        vector<vector<char>> maze(n, vector<char>(n, ' '));
                
        maze[0][1] = maze[0][3] = maze[2][1] = maze[2][3] = maze[4][1] = maze[4][3] = '|'; 
        maze[1][0] = maze[1][2] = maze[1][4] = maze[3][0] = maze[3][2] = maze[3][4] = '_';

        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<n; j++) {
        //         cout << maze[i][j] << " ";
        //     }cout << "\n" ;
        // }
    
    }

    void display() {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cout << maze[i][j] << " ";
            }cout << "\n" ;
        }
    
    }
};

class player1 : public DispMaze {
    public:

};

class player2 : public DispMaze {

};

int main () {
    return 0;
}