// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
		

	public:
	int solve(int cost[],int N,int W,vector<vector<int>> &dp)
	{
	    if(N==0 && W==0) return 0;
	    if(N==0) return 1e9;
	    if(W==0) return 0;
	    
	    if(dp[N][W]!=-1) return dp[N][W];
	    int take,nontake;
	    if(N>W || cost[N-1]==-1)
	        return dp[N][W]=solve(cost,N-1,W,dp);
	    
	    else
	    {
	        take=solve(cost,N,W-N,dp)+cost[N-1];
	        nontake=solve(cost,N-1,W,dp);
	        
	        return dp[N][W]=min(take,nontake);
	        
	    }
	}
	int minimumCost(int cost[], int N, int W) 
	{ 
        // Your code goes here
        vector<vector<int>> dp(1001,vector<int>(1001,-1));
        
        return solve(cost,N,W,dp);//==0?32767:solve(cost,N,W,dp);
	} 
};


// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends