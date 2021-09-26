#include<iostream>
#include<algorithm>
#include<vector>

int main() {

    int m, n;
    std::cin>>m>>n;
    std::vector< std::vector<int> > arr(m, std::vector< int >(n) );
    // int arr[m][n];
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            std::cin >> arr[i][j];
        }
    }

    // std::sort( (std::vector<std::vector<int>>::iterator)arr[0][0], (std::vector<std::vector<int>>::iterator)arr[m-1][n]);
    // std::sort( arr.begin(), (std::vector<std::vector<int>>::iterator)&arr[m-1][n-1]);
    std::sort(arr.begin(), arr.end());

    // std::cout << arr[m/2][n/2] << "\n";

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            std::cout << arr[i][j] << " " ;
        }
        std::cout << "\n";
    }

    // std::cout << "size of int: " << sizeof(int) << "\n";
    //  auto it = arr.begin();
    // // std::cout << "Address of arr.begin(): " << (long unsigned int)(&it) << "\n";
    // std::cout << "Address of arr[0]: " << (long unsigned int)(&arr[0]) << "\n";
    // std::cout << "Address of arr[0][1]: " << (long unsigned int)(&arr[0][0]) << "\n";
    // std::cout << "Address of arr[1]: " << (long unsigned int)(&arr[1]) << "\n";

    return 0;
}