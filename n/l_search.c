#include <stdio.h>

void l_search( int a[], int n, int key) {

	for(int i =0; i< n; i++ ) {
		
		if(a[i] == key ){
			printf("%d found on position %d", key , i+1 );
			return;
		}
	}

	printf("Not Found");
}

int main () {

	//int n, a[10], key;

	// printf("\nEnter no. of elements to enter in an array(max 10):\t");
	// scanf("%d", &n);
	
	// for(int i =0; i< n; i++ ) {
	// 	scanf("%d", &a[i]);
	// }
	
	// printf("\nEnter no. to search:\t");
	// scanf("%d", &key);
	
	int a[] ={1, 2, 3, 4};
	int n = sizeof(a)/ sizeof(a[0]), key = 2, key1 = 0;

	printf("\n---Linear Search---\nEntered Array:\t");
	for(int i=0; i<n;i++) { printf("%d ", a[i]); }

	printf("\n\nNo. to be searched = %d\n", key);
	l_search(a,n,key);

	printf("\n\nNo. to be searched = %d\n", key1);
	l_search(a,n,key1);
	
return 0;
}
