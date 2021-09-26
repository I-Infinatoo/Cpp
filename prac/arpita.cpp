#include<bits/stdc++.h>
using namespace std;

struct node{
    int profit;
    int pickUpPoint;
    int dropPoint;
};

int calc(int pick[], int drop[], int tip[], int size = 6){
    int totalProfit=0;// size=sizeof(pick)/sizeof(pick[0]);

    struct node n[size], temp;
    
    for(int i=0; i<size; i++) //number of elements
    {
        n[i].profit=drop[i]-pick[i]+tip[i];
        n[i].pickUpPoint=pick[i];
        n[i].dropPoint=drop[i];
    }

    stack <struct node>st;
    int i=1;

    st.push(n[0]);
    
    while(i<size){

        temp=st.top();
        if(temp.profit<n[i].profit){
            if(n[i].pickUpPoint<temp.dropPoint){
                st.pop();
                st.push(n[i]);
            }
            else{
                st.push(n[i]);
            }
        }
        else if(temp.profit>=n[i].profit){
            if(n[i].pickUpPoint>=temp.dropPoint) {
                
                st.push(n[i]);
            }
        }
        i++;
    }

    while(!st.empty()){
        temp=st.top();
        totalProfit+=temp.profit;
        st.pop();
    }

    return totalProfit;
}

int main() {

    int pick[] = {0,2,9,10,11,12};
    int drop[] = {5,9,11,11,14,17};
    int tip[] = {1,2,3,2,2,1};

    cout << calc(pick, drop, tip) << "\n";


    return 0;
}
