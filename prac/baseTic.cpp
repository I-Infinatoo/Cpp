#include<bits/stdc++.h>
using namespace std;

map<int, int> mp { {0,0}, {1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {6,0}, {7,0} };
vector<vector<int>> visited(3, vector<int>(3, 0));

bool retry = 0, complete = false;

void update(int r, int c, char p) {
    if( r == 0 ) {    //printf("%c[%d;%df",0x1B,y,x);
        if( c == 0 )  { printf("%c[%d;%df",0x1B,2,4); cout << p; }
        if( c == 1 )  { printf("%c[%d;%df",0x1B,2,9); cout << p; }
        if( c == 2 )  { printf("%c[%d;%df",0x1B,2,15); cout << p; }
    }
    if( r == 1 ) {
        if( c == 0 )  { printf("%c[%d;%df",0x1B,4,4); cout << p; }
        if( c == 1 )  { printf("%c[%d;%df",0x1B,4,9); cout << p; }
        if( c == 2 )  { printf("%c[%d;%df",0x1B,4,15); cout << p; }
    }
    if( r == 2 ) {
        if( c == 0 )  { printf("%c[%d;%df",0x1B,6,4); cout << p; }
        if( c == 1 )  { printf("%c[%d;%df",0x1B,6,9); cout << p; }
        if( c == 2 )  { printf("%c[%d;%df",0x1B,6,15); cout << p; }
    }
}


void gotoxy(int x,int y, int p=0){
    
    if(p==0) {
        printf("%c[%d;%df",0x1B,y,x);
        return;
    }

    update(x, y, p);
    if(p==1) update(x, y, 'X') ;
    if(p==-1) update(x, y, 'O') ;
}

void dispMaze(){
    
    int n = 5;
    
    vector<vector<char>> maze(n, vector<char>(n, ' '));
                
    maze[0][1] = maze[0][3] = maze[2][1] = maze[2][3] = maze[4][1] = maze[4][3] = '|'; 
    maze[1][0] = maze[1][2] = maze[1][4] = maze[3][0] = maze[3][2] = maze[3][4] = '_';

    for(int i=0; i<n; i++) {
        
        if(i==0) {
            cout << "   0    1     2\n";
        }
        
        for(int j=0, k=0; j<n; j++) {
        
            if(i==0 && j==0) {
                cout << "0" ;
            }
            if(i==2&& j==0) {
                cout << "1" ;  
            }
            if(i==4&& j==0) {
                cout << "2" ;
            }

            cout << " " <<maze[i][j] << " ";
        
        }cout << "\n" ;
    }
    cout << "\n\n\tPlayer 1 : X   Player 2: O";
    cout << "\n\tI/P Format: row col\n\n" ;
}


void funChange(int player, int a, int b, int c = -1, int d = -1) {
    
    //player == 1 for 1st player
    //player == -1 for 2st player  
    
    if(a!=-1) {
        mp[a] += player; 
    }
    if(b!=-1) {
        mp[b] += player; 
    }
    if(c!=-1) {
        mp[c] += player; 
    }
    if(d!=-1) {
        mp[d] += player; 
    }

    return;
}

bool isVisited(int r, int c) {
    
    return visited[r][c]; 
}

void check1(int a, int b, int c = -1, int d = -1){

    if(mp[a]==3 || mp[b]==3 || mp[c]==3 || mp[d]==3) {
        
        gotoxy(9,15,0);
        
        cout <<"Player 1[X] wins";
        complete = true;
    }
    if(mp[a]==-3 || mp[b]==-3 || mp[c]==-3 || mp[d]==-3) {
        
        gotoxy(9,15,0);

        cout <<"Player 2[O] wins";
        complete = true;
    }
    return;
}

void pass(int p, int r, int c) {

    if( isVisited(r,c) ) {
        //already filled
        
        // gotoxy(9,14,0);
        // cout << "Enter Valid move!!  Retry!!";
        
        retry = true;
        return;
    }

    if( r == 0 ) {
        if( c == 0 )  { funChange(p, 0,3,6); check1(0,3,6); }
        if( c == 1 )  { funChange(p, 1,3); check1(1,3); }
        if( c == 2 )  { funChange(p, 2,3,7); check1(2,3,7); }
    }
    if( r == 1 ) {
        if( c == 0 )  { funChange(p, 0,4); check1(0,4); }
        if( c == 1 )  { funChange(p, 1,4,6,7); check1(1,4,6,7); }
        if( c == 2 )  { funChange(p, 2,4); check1(2,4); }
    }
    if( r == 2 ) {
        if( c == 0 )  { funChange(p, 0,5,7); check1(0,5,7); }
        if( c == 1 )  { funChange(p, 1,5); check1(1,5); }
        if( c == 2 )  { funChange(p, 2,5,6); check1(2,5,6); }
    }      

    visited[r][c] = 1;

    return;  
}

bool check(int row, int col){
    return (row<3 and row >=0 and col>=0 and col<3)? true : false;
}

void play () {

    int row, col, temp;
    
    for(int i =0; i<9; i++) {
        
        if(i%2==0) {
            //player 1's turn
            
            gotoxy(9-9, 12, 0);
            cout << "Player 1[X]: Enter row and Column:\t" ;
            cin >> row >> col;

                
            //removing retry message
            gotoxy(9,14,0);
            cout << "                           ";
            
            if(check(row, col)) pass(1, row, col); 
            else retry = true;    
            
            if(retry) {     //this will allow the player to retry, not valid move
                i--;
                retry = false;
                
                gotoxy(9,14,0);
                cout << "Enter Valid move!!  Retry!!";
                
                continue;
            }

            gotoxy(row, col, 1);

            if(complete) {break;}
        }

        if(i%2!=0) {
            //player 2's turn

            gotoxy(9, 12, 0);
            cout << "\nPlayer 2[O]: Enter row and Column:\t" ;
            cin >> row >> col;

            //clearing the screen after taking input or better look
            gotoxy(9, 12, 0);
            cout << "\n                                             " ;   
            gotoxy(9-9, 12, 0);
            cout << "                                                      " ;
             
            
            //removing retry message
            gotoxy(9,14,0);
            cout << "                           ";
            
            if(check(row, col)) pass(-1, row, col); 
            else retry = true;    
            
            if(retry) {
                i--;
                retry = false;
                
                gotoxy(9,14,0);
                cout << "Enter Valid move!!  Retry!!";

                continue;
            }

            gotoxy(row, col, -1);

            if(complete) {break;}
        }
    }
    if(!complete) {
        gotoxy(9,14,0);
        cout << "Draw!\n\tBetter Luck Next time!!";
    }

    return;

}

int main () {

    system("clear");
    dispMaze();

    play();
    gotoxy(0, 18, 0);
    return 0;
}