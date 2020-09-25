#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>

using namespace std;

void merge(int arr[], int l, int m, int r) { 
    int i, j, k; 
    int d1 = m - l + 1; 
    int d2 =  r - m; 
  
    // create temp arrays for left and right of main array 
    int left[d1], right[d2]; 
  
    // Copy data to the temp arrays made above
    for (i = 0; i < d1; i++) 
        left[i] = arr[l + i]; 
    for (j = 0; j < d2; j++) 
        right[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // first subarray 
    j = 0; // second subarray 
    k = l; // merged subarray 
    while (i < d1 && j < d2) { 
        if (left[i] <= right[j]) { 
            arr[k] = left[i]; 
            i++; 
        } else{ 
            arr[k] = right[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of left[], if there 
       are any */
    while (i < d1) { 
        arr[k] = left[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of right[], if there 
       are any */
    while (j < d2) { 
        arr[k] = right[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) { 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
}

void fillArray(int arr[], int x){
//geneerates random numbers between 1 and x and fills the array 
        
        for(int i = 0; i < x; i++){

            arr[i] = rand() % x + 1;
        }
  
}


int main(){
   
    srand (time(NULL)); 

    int x = 750000; 
    int numArray[x]; //creates array of x size
    fillArray(numArray, x); //fills array with random numbers
    
    clock_t startT = clock(); 
    mergeSort(numArray, 0, x-1); //merge sort
    clock_t endT = clock();
    clock_t duration = double(endT - startT) / CLOCKS_PER_SEC * 1000; 
    cout << "Elapsed time for N = " << x  << " merge sort: " << duration << " ms" << endl;
}


