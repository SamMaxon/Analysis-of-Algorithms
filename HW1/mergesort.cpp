#include <iostream>
#include <fstream>

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

void fillArray(ifstream& data, int arr[], int x){
//checks if file is open, then fills array with data from 1 line in the file of x length
    if (data.is_open()){
        
        for(int i = 0; i < x; i++){

            data >> arr[i];
        }
    }
}

void fillFile(ofstream& merge, int arr[], int x){
//checks if file is open, then fills file with data from array with spoace between each number, then goes to new line.
    if (merge.is_open()){
        
        for(int i = 0; i < x; i++){

            merge << arr[i];
            merge << " ";
        }
    }
    merge << endl; 
}

int main(){
    ifstream data; //input file stream
    ofstream merge; //output file stream
    data.open("data.txt"); //opens our input file
    merge.open ("merge.out"); //opens our output file
    int x; 

    while (!data.eof()){ //reads till end of file

        data >> x; //grabs first number of the line
        int numArray[x]; //creates array of x size
        fillArray(data, numArray, x); //fills from file
        mergeSort(numArray, 0, x-1); //merge sort
        fillFile(merge, numArray, x); //fills file with data from array
    }
}

