#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>

using namespace std;


/* Function to sort an array using insertion sort*/
void insertSort(int arr[], int n)  
{  
    int i, j, k;  
    for (i = 1; i < n; i++) 
    {  
        k = arr[i];  
        j = i - 1;  
  
        /* Move elements from up one in the array, that are  
        greater than k, */
        while (j >= 0 && arr[j] > k) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = k;  
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
    
    int x = 100000; 
    int numArray[x]; //creates array of x size
    fillArray(numArray, x); //fills array with random numbers
    
    clock_t startT = clock(); 
    insertSort(numArray, x); //insert sort
    clock_t endT = clock();
    clock_t duration = double(endT - startT) / CLOCKS_PER_SEC * 1000; 
    cout << "Elapsed time for N = " << x << " insertion sort: " << duration << " ms" << endl;
}