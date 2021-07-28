#include<iostream>
#include<string>
#include<algorithm>

#include<ios>
#include<limits>

int main () {

    int t;
    std::cin >> t;

    while(t--) {

        std::string D, S;
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cin >> D;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cin >> S;

        // order[] will store the new lexicographical order 
        static int order[26];
        // initializing the order array
        for(int i=0; i<26; i++) order[i]=-1;

        // storing the given order
        for(int i=0; i<D.length(); i++) {
            order[ (D[i]-'a') ] = i;
        }

        // for(int i=0; i<26; i++) {
        //     std::cout << (i+'a') << ":" << order[i] << "\t";
        // }

        // sort the 'S' according to 'D'
        std::sort(S.begin(), S.end(), [](int a, int b) { 
            a = a - 'a';
            b = b - 'a';

            return order[a] < order[b]; // if this returns true then 'a' will be placed before 'b'
        });

        std::cout << S << "\n" ;
    }

    return 0;
}