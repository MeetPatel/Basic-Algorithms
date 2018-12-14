//Insertion Sort
//Reference: https://www.geeksforgeeks.org/insertion-sort/
#include<stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void InsertionSort(int* arr, int n){
	int i, j, temp;
	for(i=1; i<n-1; ++i){
		temp = arr[i];
		j = i-1;

		while(j>=0 && arr[j]>temp){
			arr[j+1] = arr[j];
			--j;
		}
		arr[j+1] = temp;
	}
}

int main(){
	int arr[5] = {3,6,4,1,9};
	const int size = 5;
	printf("Initial Array: ");
	for (int i = 0; i < size; ++i) printf("%d ", arr[i]);
	InsertionSort(arr, size);
	printf("\nFinal Array: ");
	for (int i = 0; i < size; ++i) printf("%d ", arr[i]);

	return 0;
}