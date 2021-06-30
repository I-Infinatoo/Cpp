// #include <bits/stdc++.h>

// #define lui long unsigned int


// unsigned int countSetBits(unsigned int n) {
//     unsigned int count = 0;
//     while (n) {
//         count += n & 1;
//         n >>= 1;
//     }
//     return count;
// }

// std::vector<int> acmTeam(std::vector<std::string> topic) {
//     std::vector<int> ans;
//     int max = 0;
//     //int count=0;
//     std::map<int,int>mp;
//     for(lui i=0; i<topic.size()-1; i++) {
        
//         int x = std::stoi(topic[i]);
        
//         for(lui j=i+1; j<topic.size(); j++) {
            
//             int y = std::stoi(topic[j]);
            
//             if((x | j) >= max) {
//                 max = (x | y);
//                 mp[max]++;
//             }
//         }
//     }
//     ans.push_back(max);
//     ans.push_back(mp[max]);
    
//     return ans;
// }


// int main(){

//     int n =4;
//     std::vector<std::string>s;
    
//     s.push_back("10101");
//     s.push_back("11100");
//     s.push_back("11010");
//     s.push_back("00101");

//     // std::vector<int>a = acmTeam(s);

//     // std::cout << a[0] << " " << a[1];

//     // int x = 010 | 101;
//     std::cout << countSetBits(010 | 101);
//     // printf("\n%b", x);
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
// 1 12 5 111 200 1000 10
int maximumToys(vector<int> prices, int k) {
    int count =0, sum=0;
    int i=0, j=0;
    
    sort(prices.begin(), prices.end());
    
    while( j < prices.size() ){
        
        sum+=prices[j];
        
        if(sum<=k and (j-i+1)>count){
            j++;
            count++;
        }
        else if(sum>k and i<j){
            i++;
            count--;
        }
        else if(i==j){
            j++;
            sum+=prices[j];
            count++;
        }
        
    }
    return count;
}

int main(){
    vector<int>prices;
    int k=50;
    // 1 12 5 111 200 1000 10
    prices.push_back(1);
    prices.push_back(12);
    prices.push_back(5);
    prices.push_back(111);
    prices.push_back(200);
    prices.push_back(1000);
    prices.push_back(10);
    
    int y = maximumToys(prices, k);
    cout << y;
    return 0;
}