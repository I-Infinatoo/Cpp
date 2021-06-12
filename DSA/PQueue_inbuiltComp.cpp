//Priority Queue ---> Max. Heap (by default)
//Priority Queue ---> Min. Heap (by using inbuilt comparator)

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){

    int arr[] = {10, 9, 21, 23, 1, 3, 90};

    priority_queue<int>pq_max; // by default it is Max. Heap

    priority_queue<int, vector<int>, greater<int>> pq_min; //
 
    for(int i=0; i<7; i++) { 
        cout << arr[i] << " " ;
        pq_min.push(arr[i]);
        pq_max.push(arr[i]); 
    
    } cout << "\n" ;

    while(!pq_min.empty()) {
        cout << pq_min.top() << " " ;
        pq_min.pop();
    }
    
    cout << "\n" ;

    while(!pq_max.empty()) {
        cout << pq_max.top() << " " ;
        pq_max.pop();
    }

    return 0;
}