#include<iostream>
#include<vector>
#include<limits.h>
#include<map>

void input(std::vector<int>& arr, int size){
    int temp;
    for(int i=0; i<size; i++){
        std::cin >> temp;

        arr.push_back(temp);

    }
}

const void output(std::vector<int>& arr, int size){
    for(int i=0; i<size; i++){
        std::cout << arr[i] << " " ;
    }
    std::cout << "\n";
}


// 6.reverse the array
void reverse(std::vector<int>&arr, int size) {
    int temp;
    for(int i=0, j=size-1; i<j; i++, j--){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}


// 7.find max and min value
const void MaxAndMin(std::vector<int>& arr, int size) {
    int max=INT_MIN, min=INT_MAX;

    for(int i=0; i<size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    std::cout << max << " " << min << "\n" ;
}

// 10.Move all -ve elements to one side(to right)
void moveNegativeRight(std::vector<int>& arr, int size) {
    int i=0, j=size-1, temp;
    
    while(i<j) {
        
        if(arr[j]<0) { j--; }
        
        if(arr[i] < 0 and arr[j] >=0 ) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j--; i++; 
        }
        
        if(arr[i]>=0 and arr[j] >=0) { i++; }
        
        else { j--; }
    }
}

//16.Find the duplicate in array
int findDuplicate(std::vector<int>&arr, int size) {
    
    std::map<int, bool>mp;
    int ans;

    for(int i=0; i<size; i++) {
        if(!mp[arr[i]]) {
            mp[arr[i]]=true; 
        }
        else{
            ans=arr[i];
        }    
    }
    return ans;
}


int main (){

    int size;
    std::cin >> size;

    static std::vector<int>arr;
    arr.reserve(size);

    input(arr, size);
    
    // reverse(arr, size);  //6
    
    // MaxAndMin(arr, size);    //7

    // moveNegativeRight(arr, size);   //10

    std::cout << findDuplicate(arr, size) ;   //16

    // output(arr, size); 

    return 0;
}