#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string fun (vector<int>arr) {
    string ans = "";

    //00-23 //00-59 //"hh:mm"
    
    sort(arr.begin(), arr.end());

    int h1 = 0, h2 = 0, m1 = 0, m2 = 0, v1 = 0, v2 = 0, v3 = 0, v4 = 0;
    bool flag = false;  //to check if hour is valid or not

    //for(int i=0; i<arr.size(); i++) cout << arr[i] << " ";

    for(int i=arr.size()-1; i>=0; i--){
        
        //hour
        if(arr[i]<=2 and v1 == 0) {
            h1=arr[i];
            v1 =i;
            flag = true;
        }
        if(arr[i] <= 3 and v2 == 0 and v1 != i ) {
            h2=arr[i];
            v2=i;
            flag = true;
        }
    }

    for(int i=arr.size()-1; i>=0; i--){
        
        //minute
        if(arr[i]<=5 and flag and i!=v1 and i!=v2 and v3==0) {
            m1 = arr[i];
            v3 = i;
        }
        if(arr[i]<=9 and flag and i!=v3 and i!=v1 and i!=v2 and v4==0) {
            m2 = arr[i];
            v4=i;
        }
        
    }

    //cout << "\n" << h1 << " " << h2 <<":" << m1 << " " << m2<< endl;

    if(flag == false ) { return "" ; } //if not found
    
    ans = to_string(h1) + to_string(h2) + ":" + to_string(m1) + to_string(m2); 
    
    return ans;
}


int main() {

    vector<int>arr;
    
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);

    cout << fun(arr);
    return 0;
}