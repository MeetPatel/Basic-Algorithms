//Fastest possible BubbleSort
#include<stdio.h>
#include<stdbool.h>

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void BubbleSort(int* arr, int n){
	int i,j;
	bool swapped = false;
	for (i = 0; i < n-1; ++i)
	{	
		swapped = false;	
		for (j = 0; j<n-i-1; ++j)
		{
			if(arr[j]>arr[j+1]){
				swap(&arr[j], &arr[j+1]); swapped = true;
			}
		}
		if(swapped == false) break;
	}
}

int main(){
	int arr[5] = {3,6,4,1,9};
	const int size = 5;
	printf("Initial Array: ");
	for (int i = 0; i < size; ++i) printf("%d ", arr[i]);
	BubbleSort(arr, size);
	printf("Final Array: ");
	for (int i = 0; i < size; ++i) printf("%d ", arr[i]);
	return 0;
}