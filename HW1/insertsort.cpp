#include <iostream>
#include <fstream>

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

void fillArray(ifstream& data, int arr[], int x){
//checks if file is open, then fills array with data from 1 line in the file of x length
    if (data.is_open()){
        
        for(int i = 0; i < x; i++){

            data >> arr[i];
        }
    }
}

void fillFile(ofstream& insert, int arr[], int x){
//checks if file is open, then fills file with data from array with spoace between each number, then goes to new line.
    if (insert.is_open()){
        
        for(int i = 0; i < x; i++){

            insert << arr[i];
            insert << " ";
        }
    }
    insert << endl; 
}

int main(){
    ifstream data; //input file stream
    ofstream insert; //output file stream
    data.open("data.txt"); //opens our input file
    insert.open ("insert.out"); //opens our output file
    int x; 

    while (!data.eof()){ //reads till end of file

        data >> x; //grabs first number of the line
        int numArray[x]; //creates array of x size
        fillArray(data, numArray, x); //fills from file
        insertSort(numArray, x); //insert sort
        fillFile(insert, numArray, x); //fills file with data from array
    }
}