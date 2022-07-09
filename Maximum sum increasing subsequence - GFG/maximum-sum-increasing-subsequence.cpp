// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	
	int dp[1005][1005];
	int solve(int arr[],int n,int prev,int limit)
	{
	    if(n==0)  return 0;
	    if(dp[n][prev]!=-1) return dp[n][prev];
	    
	    int take=0;
	    if(prev==limit+1 || (prev<limit+1 && arr[prev]>arr[n-1]))
	         take=arr[n-1]+solve(arr,n-1,n-1,limit);
	    int not_take= solve(arr,n-1,prev,limit);
	    
	    return dp[n][prev]=max(take,not_take);
	}
	
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    memset(dp,-1,sizeof(dp));
	    int prev=n+1;
	    return solve(arr,n,prev,n);
	    
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends