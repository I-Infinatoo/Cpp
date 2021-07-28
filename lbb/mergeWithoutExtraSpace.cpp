#include<iostream>
#include<algorithm>
#include<cmath>

void o_put(int a[], int b[], int n, int m){
    for(int i=0; i<n; i++){
        std::cout << a[i] << " ";
    } std::cout << std::endl;
    for(int i=0; i<m; i++){
        std::cout << b[i] << " ";
    } std::cout << std::endl;
}

void sort(int b[], int m){
    for(int i=1; i<m; i++){
        if(b[i-1]>b[i]){
            int temp = b[i-1];
            b[i-1]=b[i];
            b[i]=temp;
        }
    }
}

void merge(int a[], int b[], int n, int m){
    
    for(int i=0; i<n; i++){
        if(a[i]>b[0]) {
            // swap
            int temp=a[i];
            a[i]=b[0];
            b[0]=temp;

            // sort b[]
            sort(b,m);
        }
    }
}

// void mergeUsingGap(int a[], int b[], int n, int m){
//     int gap = std::ceil((n+m)/2);
//     while(gap>=1){
//         int i=0;

//         while(i<n){
//             if(i<n){ i=0; }
//             i++;
//         }

//         gap=std::ceil(gap/2);
//     }
// }

int main() {

    int a[]={1,5};
    int b[]={2,3,4,7,8};

    int n=sizeof(a)/sizeof(a[0]);
    int m=sizeof(b)/sizeof(b[0]);

    merge(a,b,n,m);
    // mergeUsingGap(a, b, n, m);
    
    o_put(a, b, n, m);
    return 0;
}