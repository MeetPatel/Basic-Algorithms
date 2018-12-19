//Binary Search, Recursive implementation. Reference: https://www.geeksforgeeks.org/binary-search/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int binarySearch(int arr[], int l, int r, int find){
    if(l<=r){
        int mid = l+(r-l)/2;

        if(find == arr[mid]) return mid;
        else if(find < arr[mid]) return binarySearch(arr, l, mid-1 ,find);
        else return binarySearch(arr, mid+1, r, find);
    }
    return -1;
}

int main(){
    int arr[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int n = 20;
    printf("Initial array:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    int index = binarySearch(arr, 0, n-1, 7);
    if(index ==-1) printf("\n%d was not found.\n", 7);
    else printf("\n%d was found at index %d.\n", 7, index);

    return 0;
}
