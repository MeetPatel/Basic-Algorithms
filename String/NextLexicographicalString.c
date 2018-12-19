//Program to find next lexicographically possible string.
//Reference: https://www.nayuki.io/page/next-lexicographical-permutation-algorithm

/*


    1) Find largest index i such that array[i − 1] < array[i].
       (If no such i exists, then this is already the last permutation.)

    2) Find largest index j such that j ≥ i and array[j] > array[i − 1].

    3) Swap array[j] and array[i − 1].

    4) Reverse the suffix starting at array[i].

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char arr[101];
    printf("Enter string (without spaces):");
    scanf("%s", arr);
    int len = strlen(arr);
    if(len==0){
        printf("Invalid String.\n"); return 0;
    }
    int i = len-1;
    while(i>0){
        if(arr[i-1]<arr[i]) break;
        i--;
    }
    if(i==0){
        printf("Next lexicographical String not possible.\n"); return 0;
    }

    int j = len-1;
    while(j>=i){
        if(arr[j]>arr[i-1]) break;
        j--;
    }

    int temp = arr[j]; //swapping arr[i-1] and arr[j]
    arr[j] = arr[i-1];
    arr[i-1] = temp;

    j = len - 1;  //reversing the suffix(lexicographically largest rightmost substring).
    while(i<j){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        j--; i++;
    }
    
    printf("Next lexicographical string is:\n");
    printf("%s\n", arr);
    

    return 0;
}
