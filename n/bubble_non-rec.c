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

void bubble_Sort(int a[], int n) {
    
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n - i- 1; j++) {
            
            if (a[j] > a[j+1]) {
                swap(a, j, j+1);
            }
        }
    }
}

int main()
{
    int a[] = {2, 4, 1, 3};
    int n = sizeof(a) / sizeof(a[1]);

    printf("\n---Bubble Sort---\nEntered Array:\t");
    print_array(a, n);
    
    bubble_Sort(a, n);

    printf("\nSorted array:\t");
    print_array(a, n);
    return 0;
}
