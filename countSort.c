#include<stdio.h>
#include<stdlib.h>

void printArray(int a[], int n){
    for(int i = 0; i<n; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void countSort(int a[], int size){
    // finding max element
    int max = a[0];
    for(int i = 1; i<size; i++){
        if(a[i] > max){
            max = a[i];
        }
    }
    
    // creating array of length = max + 1
    max++;
    int *countArr = (int *)calloc(max, sizeof(int));
    for(int i = 0; i< size; i++){
        countArr[a[i]]++;
    }

    // sorting array
    int i = 0, j = 0;

    while(i <= max){
        if(countArr[i] > 0){
            a[j] = i;
            countArr[i]--;
            j++;
        }
        else{
            i++;
        }
    }
}

int main()
{
    int a[] = {3,4,9,9,2,3,4,1};
    int size = sizeof(a)/sizeof(a[0]);
    printArray(a, size);
    countSort(a,size);
    printArray(a,size);
    return 0;
}