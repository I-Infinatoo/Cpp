#include <stdio.h>

void print_array(int a[], int n){
    
    for (int i=0; i < n; i++) {
        
        if ( i == n-1) {
            printf("%d", a[i]);
        
        } else {
        
        printf("%d, ", a[i]);
        }
    }    
}

void swap (int a[], int i, int j) {
    
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition (int a[], int low, int high) {
    
    int pivot = a[low], left = low, right = high;
    
    while ( left  <  right ) {
        while ( a[left]  <= pivot ) {
            left++;
        } 
        while ( a[right] > pivot ) {
            right--;
        }
        if (left < right) {
            swap(a, left, right);
        }
    }
    swap(a, low, right);
    
    return right;
}

void quick_sort(int a[], int low, int high) {
    
    if (low <= high) {
        int pos = partition(a, low, high);
        
        quick_sort(a, low, (pos-1) );
        quick_sort(a, (pos+1), high);
        
    }
}

void array() {
    // int n;
    // printf("\nEnter no. of elements to enter in an array:\t");
    // scanf("%d", &n);
    
    // int a[n];
    // printf("\nEnter elements in array:\t");
    // for(int i=0; i < n;i++) {
    //     scanf("%d", &a[i]);
    // }
    int a[] = {2, 1, 4, 3, 2};
    int n = sizeof(a)/sizeof(a[0]);

    printf("\n---Quick Sort---\nEntered Array:\t");
    print_array(a, n);

    quick_sort(a, 0, (n-1));
    
    printf("\nSorted array:\t");
    print_array(a, n);
}


int main()
{
    array();

    return 0;
}
