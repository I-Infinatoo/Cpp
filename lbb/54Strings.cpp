#include<iostream>
#include<map>

// void input(char *str){
    
//     std::cin >> str;
// }

// void o_put(const char* str) {
//     std::cout << str << "\n" ;
// }


void findDuplicate(char str[]){
    std::map<char, int>mp;

    for(int i=0; str[i]!='\0'; i++){
        mp[str[i]]++;  
    }

    std::map<char, int>::iterator i;
    for(i=mp.begin(); i!=mp.end(); i++){
        if(i->second>1){
            std::cout<<i->first << "=" << i->second << "\n";
        }
    }
}

int main() {
    char str[]="isishuisrajanis";
    // input(str);

    findDuplicate(str);
    // o_put(str);
    return 0;
}