#include <stdio.h>

void bSearch(int a[], int n, int key) {

    int l = 0,  h= n-1;

    while(l<=h) {

        int mid = l + (h-l)/2;  // this is used there is very large number of data in an array
            //mid =  (l+h)/2;
        
        if ( a[mid] == key ) {
            printf("\nFound at : %d", mid+1);
            return;
        }

        else if (a[mid] > key ) {
            h= mid-1;
        }
        else{
            l = mid+1;
        }
    }  
    printf("Not Found"); 
    return;
}

int main () {

    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof (a)/ sizeof(a[0]), key = 2, key1 = 6;
   
    printf("\n---Binary Search---\nEntered Array:\t");
	for(int i=0; i<n;i++) { printf("%d ", a[i]); }

	printf("\n\nNo. to be searched = %d\n", key);
	bSearch(a,n,key);

	printf("\n\nNo. to be searched = %d\n", key1);
	bSearch(a,n,key1);
     
    return 0;
}