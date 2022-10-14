//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
   vector<vector<int>> dp;
    
    int solve(int n,int k)
    {
        if(n==1)  return k;
        if(k==0) return 0;
        
        if(dp[n][k]!=-1)  return dp[n][k];
        int ans=INT_MAX;
        for(int i=1;i<=k;i++)
        {
            int temp=max(solve(n-1,i-1),solve(n,k-i));
            ans=min(ans,1+temp);
        }
        return dp[n][k]=ans;
    }
    
    int eggDrop(int n, int k) 
    {
        // your code here
        dp.resize(201,vector<int>(201,-1));
         return solve(n,k);
       // return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends