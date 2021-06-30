#include<iostream>
#include<string>
#include<stack>

void str_add(std::string str1, std::string str2){
    
    std::stack<char> add;   //stack is used to store result in correct order!!
    
    int i=str1.size()-1, j=str2.size()-1;
    int carry = 0;
    
    for( ; j>=0 and i>=0; i--, j--){
        
        int temp = (str1[i] - '0') + (str2[j] - '0') + carry;
        
        add.push(char(temp%10));
        
        carry = temp/10;
        
    }
    while(i>=0) {
        
        int temp = (str1[i] - '0')  + carry;
        add.push(char(temp%10));
        i--;
    }
    while(j>=0) {
        
        int temp = (str2[j] - '0')  + carry;
        add.push(char(temp%10));
        j--;
    }

    while ( !add.empty() ) {
        
        std::cout << int(add.top());
        add.pop();
        
    }
    
    std::cout << '\n';
}

int main(){
    
    static std::string str1 ="123";
    static std::string str2 ="278";
    
    str_add(str1, str2);
    
    return 0;
}