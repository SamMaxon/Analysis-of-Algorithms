#include <iostream>
#include <fstream>
#include <bits/stdc++.h> 

using namespace std;

void addEdge(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 
  
// function to check whether a graph is bipartite or not 
bool isBipartite(vector<int> adj[], int v, 
                 vector<bool>& visited, vector<int>& color) 
{ 
  
    for (int u : adj[v]) { 
  
        // if vertex u is not explored before 
        if (visited[u] == false) { 
  
            // mark present vertic as visited 
            visited[u] = true; 
  
            // mark its color opposite to its parent 
            color[u] = !color[v]; 
  
            // if the subtree rooted at vertex v is not bipartite 
            if (!isBipartite(adj, u, visited, color)) 
                return false; 
        } 
  
        // if two adjacent are colored with same color then 
        // the graph is not bipartite 
        else if (color[u] == color[v]) 
            return false; 
    } 
    return true; 
} 

int main(){
    ifstream data; //input file stream
    ofstream change; //output file stream
    string f = ""; 
    int n; 

    cout << "Enter in the file name and extension for the input file" << endl;
    cin >> f; 
    cout << endl; 

    data.open(f); //opens our input file
    data >> n;  
  
    string w[n]; //wrestlers names
    // to maintain the adjacency list of graph 
    vector<int> adj[n + 1]; 
  
    // to keep a check on whether 
    // a node is discovered or not 
    vector<bool> visited(n + 1); 
  
    // to color the vertices 
    // of graph with 2 color 
    vector<int> color(n + 1);

    string x; 
    string y; 
    int k; 
    int e; 
    int b; 
    for(int i = 0; i < n; i++){
        data >> x; 
        w[i] = x; 
    }
    data >> k;
    for(int i = 0; i < k ; i++){
        data >> x; 
        data >> y; 
        for(int j = 0; j < n; j++){
            if(x == w[j]){
                e = j; 
            }
            if(y == w[j]){
                b = j; 
            }
        }
        addEdge(adj, e, b);
    }
        
    visited[1] = true; 

    color[1] = 0; 
    
    if (isBipartite(adj, 1, visited, color)) { 
        cout << "Graph is Bipartite"; 
    } 
    else { 
        cout << "Graph is not Bipartite"; 
    } 
  
    return 0; 
}