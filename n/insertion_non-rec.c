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

void insertion_Sort(int a[], int n) {
    
    for (int i = 1; i < n; i++) {
        
        int temp = a[i] ;
        int j;
        for (j = i-1; j >=0 && a[j] > temp; j--) {
            
            a[j+1] = a[j];
            
        }
        a[j+1] = temp;
    }
}

int main()
{
    int a[] = {2, 4, 3, 1, 2};
    int n = sizeof(a) / sizeof(a[0]);

    printf("\n---Insertion Sort---\nEntered Array:\t");
    print_array(a, n);
    
    insertion_Sort(a, n);
    
    printf("\nSorted array:\t");
    print_array(a, n);

    return 0;
}
