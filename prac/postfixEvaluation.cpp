#include<iostream>
#include<stack>
#include<vector>

int postfixEvaluation(std::vector<char>& arr) 
{
    std::stack<int> st;

    for(auto i : arr) {
        
        if(i >= 48 and i<=57 ){
            st.push(i - '0');
        }

        else{
            int temp = st.top();
            st.pop();
            int temp2 = st.top();
            st.pop();

            switch(i)
            {
                case '+' : st.push(temp2 + temp); break;
                case '-' : st.push(temp2 - temp); break;
                case '*' : st.push(temp2 * temp); break;
                case '/' : st.push(temp2 / temp); break;
            }
        }
    }
    int ans =  st.top();
    st.pop();
    return ans;
}

bool check(char temp){

    return (temp>=48 and temp<=57) or (temp==43 or temp==45 or temp==42 or temp==47 or temp==37) ;
}

void input(std::vector<char>& arr) {

    int size;
    std::cout << "\nEnter number of expressions:\t";
    std::cin >> size;

    for(int i=0; i<size; i++){
        
        char temp;
        std::cin >> temp;
        
        if(check(temp)){

            arr.push_back(temp);
        }
        else {
            std::cout << "\nNot a valid char! ";
            exit(0);
        }
            
    }

}

int main() {

    std::vector<char> arr ;//{'2','1','+','3','*'};

    input(arr);

    std::cout << postfixEvaluation(arr) << std::endl;

    return 0;
}