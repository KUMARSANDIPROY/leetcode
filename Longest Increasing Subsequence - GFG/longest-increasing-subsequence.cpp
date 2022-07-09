// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int solve(int n,int a[],int ind,int prev,vector<vector<int>> &dp)
    {
        if(ind==n)
        {
            return 0;
        }
         // cout<<"yes ";
        if(dp[ind][prev+1]!=-1) 
              return dp[ind][prev+1];
      
          int take=0;
        if(prev==-1 || (prev!=-1 &&  a[ind]>a[prev]))
        {
            
            take=1+solve(n,a,ind+1,ind,dp);
            
        }
        
        int not_take=solve(n,a,ind+1,prev,dp);
      
        
        return dp[ind][prev+1]=max(take,not_take);
    }
    
    int longestSubsequence(int n, int a[])
    {
       // your code here
       int prev=-1;
       int ind=0;
       vector<vector<int>> dp(n,vector<int>(n+1,-1));
       return solve(n,a,ind,prev,dp);
       
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends