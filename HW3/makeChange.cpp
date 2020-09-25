#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int makeChange(int coins[], int changeArr[],  int n, int k){

    if(n == 0){ //if amount is zero we have accomplished the correct change amount and can return 0 to end the recursion. 
        return 0;  
    }

    for (int i = k+1; i > 0; i--){
        int coin = coins[i-1]; // coin grabs the largest denomination first from the coin array
       
        if(n >= coin){ // if denomination is less than amount, it can be added to our coin usage array and makeChange is recursivley called with new amount after coin is subtracted from amount. 
            changeArr[i-1] = 1 + changeArr[i-1]; 
            return 1 + makeChange(coins, changeArr, n-coin, k);  
        } 
    }
}




void fillArray(int coins[], int changeArr[], int c, int k){
//fills array with k coins of value c^0 -> c^k and initializes changeArr with zeros
    
        for(int i = 0; i < k+1; i++){
            coins[i] = pow(c, i); 
            changeArr[i] = 0; 
        }        
        return; 
}

void fillFile(ofstream& change, int coins[], int changeArr[], int c, int k, int n, int coinTot){

    if (change.is_open()){
        // fills file with the c, k, and n value we got from the original data file
        change << "Data input: c = " << c << ", k = " << k << ", n = " << n << "\n";
        for (int i = k+1; i > 0; i--){ //fills file with the denomination from largest to smallest and the amount of times the denomination was used. 
            change << "Denomination: " << coins[i-1] << " | Quantity: " << changeArr[i-1] << "\n"; 
        }
        change << "Total Coins Used: " << coinTot << "\n" << "\n"; 
    }
}

int main(){
    ifstream data; //input file stream
    ofstream change; //output file stream
    data.open("data.txt"); //opens our input file
    change.open ("change.txt"); //opens our output file
    
    int c; 
    int k;
    int n;  
    
    while (!data.eof()){ //reads till end of file

        data >> c; //grabs base
        data >> k; //grabs number of denominations 
        data >> n; //grabs change needed
        
        int coins[k+1]; //creates array of k+1 size for coin denominations
        int changeArr[k+1]; //creates array of k+1 size for storing change 
        
        fillArray(coins, changeArr, c, k); //fills array from number gotten from fill
        int coinTot = makeChange(coins, changeArr, n, k); 
        fillFile(change, coins, changeArr, c, k, n, coinTot); //fills change file with data from array and from data file
    }
}