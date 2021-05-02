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


void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void selection_Sort(int a[], int n) {
    
    for (int i = 0; i < n-1; i++) {
        
        int idx = i ;
        for (int j = i+1; j < n; j++) {
            
            if (a[j] < a[idx]) {
                idx = j;
            }
        }
        swap(a, i, idx);
    }
}

int main()
{
    int a[] = {2, 4, 3, 1, 2};
    int n = sizeof(a) / sizeof(a[0]);
    printf("\n---Selection Sort---\nEntered Array:\t");
    print_array(a, n);

    selection_Sort(a, n);
    
    printf("\nSorted array:\t");
    print_array(a, n);


    return 0;
}
