#include<iostream>
#include<vector>

void spiralTraversal(std::vector<std::vector<int>>&arr, int r, int c) {

    // dir=0 : from upper left to right; dir=1 : from rightmost top to bottom
    // dir=2 : from lower right to left; dir=3 : from leftmost bottom to top 
    
    int direction = 0, top = 0, left =0, bottom=r-1, right = c-1;

    while(top<=bottom and left<=right) {
        
        
        if (direction==0) {
            for(int i=left; i<=right; i++){ std::cout << arr[top][i] << " "; }    
            top+=1;
        }

        else if (direction==1) {
            for(int i=top; i<=bottom; i++){ std::cout << arr[i][right] << " "; }    
            right-=1;
        }

        else if(direction==2) {
            for(int i=right; i>=left; i--){ std::cout << arr[bottom][i] << " "; }    
            bottom-=1;
        }

        else if(direction== 3) {
            for(int i=bottom; i>=top; i--){ std::cout << arr[i][left] << " "; }    
            left+=1;
        }
        direction = (direction+1)%4;
    }

}

int main() {

    int r, c;
    std::cin >> r >> c;

    std::vector<std::vector<int>>arr(r, std::vector<int>(c));
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            std::cin >> arr[i][j];
        }
    }
    
    spiralTraversal(arr,r,c);

    return 0;
}