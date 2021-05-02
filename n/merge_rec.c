#include <stdio.h>
#include <malloc.h>

void print_array(int a[], int n){
    
    for (int i=0; i < n; i++) {
        
        if ( i == n-1) {
            printf("%d", a[i]);
        
        } else {
        
        printf("%d, ", a[i]);
        }
    }    
}

void merge (int a[], int low, int mid, int high) {
    int i = low, j = mid+1, k = 0; 
    int *temp = (int*) malloc (50);     

    while (i <= mid && j <= high) {
        
        if(a[i] < a[j]) {
            temp[k++] = a[i++];
        
        } else {
            temp[k++] = a[j++];
        }
    }
    
    while (i <= mid) {
        temp[k++] = a[i++];
    }
    while (j <= high) {
        temp[k++] = a[j++];
    }
    
    k=0;
    for ( i = low; i<= high; i++) { 
        a[i] = temp[k++];
    }
    
    free(temp);
}

void merge_sort(int a[], int low, int high) {
    
    if (low < high) {
        int mid = (low+high) / 2;
        merge_sort(a, 0, mid);
        merge_sort(a, (mid+1), high);
        merge (a, low, mid, high);
    }
}

void array() {
//     int n;
//     printf("\nEnter no. of elements to enter in an array:\t");
//     scanf("%d", &n);
    
//     int a[n];
//     printf("\nEnter elements in array:\t");
//     for(int i=0; i < n;i++) {
//         scanf("%d", &a[i]);
//     }
    int a[] = {2, 4, 3, 5, 1, 2};
    int n = sizeof(a) / sizeof(a[0]);

    printf("\n---Merge Sort---\nEntered Array:\t");
    print_array(a, n);
    
    merge_sort(a, 0, (n-1));
    
    printf("\nSorted array:\t");
    print_array(a, n);
}


int main()
{
    array();

    return 0;
}
