#include<iostream>
#include<stack>

int main() {
    
    int t;
    std::cin >> t;

    while(t--) {
        int n, count = 0;
        std::cin >> n;

        // unsigned int arr[n], variable = -1;
        unsigned int temp, variable = -1;
        // std::stack<unsigned int> st;
        
        for(int i=0; i<n; i++) { 
            // std::cin >> arr[i];
            std::cin >> temp;
    
            // if(i!=0 and arr[i] > st.top() ) {  
            if(i!=0 and temp > variable ) {  
                // st.push(arr[i]);
                // variable = arr[i];
                variable = temp;
                ++count;
            }

            else if ( i==0 ){                 //for first value
                // st.push(arr[i]);
                // variable = arr[i];
                variable = temp;
                ++count;
            } 

        }

        std::cout << count << "\n" ;

    }    
    
    return 0;
}