// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    /*  int static dp[201][201];
            for(int i=0;i<201;i++) 
            {
                for(int j=0;j<201;j++)
                  dp[i][j]=-1;
            }*/
   
    int solve(int n,int k,vector<vector<int>> &dp)
    {
                if(dp[n][k]!=-1) return dp[n][k];
                if(k==0 || k==1 ) return k;
                
                if(n==1) return k;
           
                
                int mn=INT_MAX;
                
                for(int i=1;i<=k;i++)
                {
                    int temp=1+max(solve(n,k-i,dp),solve(n-1,i-1,dp));
                    mn=min(mn,temp);
                }
                return dp[n][k]=mn;
    }
    int eggDrop(int n, int k) 
    {
        
                // your code here
         vector<vector<int>> dp(209, vector<int> (209, -1));       
           return solve(n,k,dp);     
           
    }
};

// { Driver Code Starts.
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