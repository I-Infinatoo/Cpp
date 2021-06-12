#include<iostream>

int main() {

    int D=5,d=2,p=1,q=2;
    //std::cin >>D>>d>>p>>q;

    int count =-1, sum =0;// i=0;

    for(int j=0; j<D; j++) {
        
        //i =j+1;
        //std::cout << i <<" ";
        if(j%d == 0) {
            count++;
            if(count==0)
                p=p;
            else{ 
                p=p+q; 
            }
            sum+=p;
        
        } else{

            sum+=p;
        }

    }

    std::cout << sum <<"\n" ;
}