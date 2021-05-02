#include <iostream>
using namespace std;

int large(int arr[], int n) {

	int max = arr[0];
	for (int i = 1; i < n; i++) {
		if( arr[i] > max)
			max = arr[i];
	}
	return max;
}

int NoOfDigits(int n) {
	int count = 0;
	
	while(n!=0){
		n/=10;
		count++;	
	}
	
	return count;
}

void redixsort(int arr[], int n) {

	int Large = large(arr, n);
	int nop = NoOgDigits(Large);
	int pass = 0, i;
	
	while ( pass <= nop-1) {
	
		i = 0;
		
		while( i < n-1 ) {
			
		}
	}
}

int main () {

	int arr = {5, 4, 1, 2, 6, 3};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	redixsort(arr, size);
	print_arr(arr, size); 

return 0;
}
