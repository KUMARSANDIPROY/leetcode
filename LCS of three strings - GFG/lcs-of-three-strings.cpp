// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


  int dp[25][25][25];
int solve(string A, string B, string C, int n1, int n2, int n3)
{
 if(n1==0 || n2==0 || n3==0)
       return 0;
    if(dp[n1][n2][n3]!=-1)
        return dp[n1][n2][n3];
    int l1=0;
    int l2=0;
    
    if(A[n1-1]==B[n2-1] && A[n1-1]==C[n3-1])
       l1=1+solve(A,B,C,n1-1,n2-1,n3-1);
    
    
    else
    {
        l2=max(solve(A,B,C,n1-1,n2,n3),max(solve(A,B,C,n1,n2-1,n3),solve(A,B,C,n1,n2,n3-1)));
    }
    
    return dp[n1][n2][n3] = max(l1,l2);
}

int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
  
    memset(dp,-1,sizeof(dp));
    
    return solve(A,B,C,n1,n2,n3);
   
    
}