//
//  Sort.c
//  COSC450_Lab1
//
//  Created by Aaron Davis on 9/12/16.
//  Copyright © 2016 Frostburg State University. All rights reserved.
//

#include "main.h"
void quickSort(int[], int, int);

int quickSortTester(){
    
    int n, ran;
    time_t t;
    
    //Initializes randum number gengerator
    srand((unsigned) time(&t));
    
    //Asks for number of integers to be stored in array
    //Initializes array
    printf("Enter the size of the array\n");
    scanf("%d", &n);
    
    int arr[n];
    
    //Places random numbers in array, range from 1 to 50
    for(int i = 0; i < n; i++){
        
        ran = 1 + rand() % 50;
        arr[i] = ran;
    }
    
    printf("Array before sort: ");
    //Prints array before sort
    for(int i = 0; i < n; i++){
        printf("%d, ", arr[i]);
    }
    printf("\n");
    
    //Calling quick sort method
    quickSort(arr, 0, n-1);
    
    printf("Array after sort: ");
    //Array after quicksort method
    for (int i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
    }
    
    return 0;
}

void quickSort(int *arr, int low, int high)
{
    int pivot, i, j, temp;
    
    if(low < high) {
        
        //Setting pivot to low index
        pivot = low;
        i = low;
        j = high;
        
        while(i < j) {
            
            //Increment i till you get a number greater than the pivot element
            while(arr[i] <= arr[pivot] && i <= high)
                i++;
            
            //Decrement j till you get a number less than the pivot element
            while(arr[j] > arr[pivot] && j >= low)
                j--;
            
            // if i < j swap the elements in locations i and j
            if(i < j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        
        //When i >= j it means the j-th position is the pivot element,
        //Swap the pivot element with the
        
        temp = arr[j];
        arr[j] = arr[pivot];
        arr[pivot] = temp;
        
        // Repeat quicksort for the two sub-arrays, one to the left of j, the other to the right
        quickSort(arr, low, j-1);
        quickSort(arr, j+1, high);
    }
}
