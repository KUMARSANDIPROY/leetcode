// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool is_safe(bool graph[101][101],int node,int col,vector<int> &color,int n)
{
    for(int i=0;i<n;i++)
    {
        if(node !=i && graph[node][i]==1 && color[i]==col)
           return false;
    }
   
    return true;
}
bool solve(bool graph[101][101],int node ,int m, int n,vector<int> &color)
{
    if(node==n) return true;
    
    for(int col=1;col<=m;col++)
    {
        if(is_safe(graph,node,col,color,n))
        {
             color[node]=col;
            if(solve(graph,node+1,m,n,color))
               return true;
            else color[node]=0;
        }
    
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    
    vector<int> color(n,0);
    return solve(graph,0,m,n,color);
    
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends