#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void insertSort(int w[], int n)  //insert sort used in HW1 to sort our array for first fit decreasing
{  
    int i, j, k;  
    for (i = 1; i < n; i++) 
    {  
        k = w[i];  
        j = i - 1;  
  
        /* Move elements from up one in the array, that are  
        less than k, */
        while (j >= 0 && w[j] < k) 
        {  
            w[j + 1] = w[j];  
            j = j - 1;  
        }  
        w[j + 1] = k;  
    }  
} 

int firstFit(int weights[], int n, int c){ 

    // number of bins
    int bins = 0; 
  
    // remaining bin storage 
    int r_b_s[n]; 
  
    // Place items one by one 
    for (int i = 0; i < n; i++) { 
        // Find the first bin that fits weight[i] 
        int j; 
        for (j = 0; j < bins; j++) { 
            if (r_b_s[j] >= weights[i]) { 
                r_b_s[j] = r_b_s[j] - weights[i]; 
                break; 
            } 
        }
  
        // If no bin could accommodate weight[i] 
        if (j == bins) { 
            r_b_s[bins] = c - weights[i]; 
            bins++; 
        } 
    } 
    return bins; 
} 

int firstFitDec(int weights[], int n, int c){
   
    int bins = 0; 
    
    insertSort(weights, n); 
    bins = firstFit(weights, n, c);
    
    return bins; 
}

int bestFit(int weights[], int n, int c){ 
    
    // number of bins
    int bins = 0; 
  
    // remaining bin storage 
    int r_b_s[n]; 
  
    // Place items one by one 
    for (int i = 0; i < n; i++) { 
        // Find the best bin that fits weight[i] 
        int j; 

        //minimum space left and index of best bin 
        int min = c + 1; 
        int best = 0; 
  
        for (j = 0; j < bins; j++) { 
            if (r_b_s[j] >= weights[i] && r_b_s[j] - weights[i] < min) { 
                best = j; 
                min = r_b_s[j] - weights[i]; 
            } 
        } 
  
        // create new bin if no bins left to fit
        if (min == c + 1) { 
            r_b_s[bins] = c - weights[i]; 
            bins++; 
        } 
        else // item goes to best bin 
            r_b_s[best] -= weights[i]; 
    } 
    return bins; 
} 

void printResults(int r1, int r2, int r3, int count){ 
    
    cout << "Test Case " << count; 
    cout << " First Fit: " << r1 << ", ";
    cout << "First Fit Decreasing: " << r3 << ", "; 
    cout << "Best Fit: " << r2 << endl; 
} 

void fillArray(ifstream& data, int w[], int n){

//checks if file is open, then fills array with data from 1 line in the file of x length
    if (data.is_open()){
        
        for(int i = 0; i < n; i++){

            data >> w[i];
        }
    }
}

int main(){
    
    ifstream data; //input file stream
    data.open("bin.txt"); //opens our input file

    int x = 0; //number of cases
    int c = 0; //bin capacity
    int n = 0; //number of items
    int r1, r2, r3; //results of algs
    int count = 1; //count of cases 
    data >> x; //grabs number of cases

    while (!data.eof()){ //reads till end of file
       
        data >> c;
        data >> n;  
        int weights[n]; //creates array of x size
        fillArray(data, weights, n); //fills from file

        r1 = firstFit(weights, n, c); //first fit alg
        r2 = bestFit(weights, n, c); // best fit
        r3 = firstFitDec(weights, n, c); //first fit decreasing alg 

        printResults(r1, r2, r3, count);

        count++; 
    }
}