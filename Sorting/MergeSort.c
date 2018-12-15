//  Merge Sort
//  reference: https://www.geeksforgeeks.org/merge-sort/
//
//  Created by Meet Patel.
//  Copyright © 2018 MPatel. All rights reserved.


#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r){
    int i,j,k;
    int n1 = m-l+1;     //no. of members in 1st half //m-l+1(one)
    int n2 = r-m;       //no. of members in 2nd half
    
    int L[n1], R[n2];   //Temp arrays
    
    for(i=0; i<n1; i++){    //copy data to left temp array
        L[i] = arr[l+i];
    }
    for(j=0; j<n2; j++){    //copy data to right temp array
        R[j] = arr[1+m+j];  //m+1(one) + j
    }
    
    i=0;    //initial index of first sub-array
    j=0;    //initial index of second sub-array
    k = l;  //initial index of merged sub-array
    
    while(i<n1 && j<n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++; k++;
        }
        else
        {
            arr[k] = R[j];
            j++; k++;
        }
    }
    
    while(i<n1){
        arr[k] = L[i];
        i++; k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++; k++;
    }
}

void mergeSort(int arr[], int l, int r){
    if(l<r){
        int mid = l + (r-l)/2;  //same as (l+r)/2
        
        mergeSort(arr, l, mid);     //Sort left half
        mergeSort(arr, mid+1, r);     //Sort right half
        
        merge(arr, l, mid, r);        //Merge sorted left and sorted right halves
    }
}

int main() {
    const int n =5;
    int arr[5] = {3,6,2,0,5};
    printf("Initial array: ");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    mergeSort(arr, 0, n-1);
    printf("\nFinal Array: ");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    return 0;
}
