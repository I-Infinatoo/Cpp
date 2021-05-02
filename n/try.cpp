#include<iostream>
using namespace std;

int main () {

	int *a = NULL, num, counter = 0;
	char ch = 'y';
	
	do{
		cout << "\nEnter a num:\n" ;
		cin >> num;
		
		a = (int *) new int;
		a[counter++] = num;
		
		cout << "\nWant to add more?(y/n)\t" ;
		cin >> ch;
	
	}while( ch == 'y');

	cout << "\nCounter\t" << counter << endl << "Array Contains:" << endl;

	for ( int i = 0; i < counter; i++ ) {
		cout << a[i] << "\t";
	}
	
	cout << endl;
return 0;
}
