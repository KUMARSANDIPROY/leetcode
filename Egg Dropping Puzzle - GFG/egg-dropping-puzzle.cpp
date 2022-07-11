// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
        int dp[n+1][k+1];
        
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                if(j==0)
                   dp[i][j]=0;
                else if(j==1)
                   dp[i][j]=1;
                else if(i==1)
                   dp[i][j]=j;
                   
                else if(i>1)
                {
                  
                    int mn=INT_MAX;
                    int mx;
                    for(int mj=j-1,pj=0; mj>=0;mj--,pj++)
                    {
                        mx=max(dp[i-1][pj],dp[i][mj]);
                        mn=min(mn,mx);
                    }
                    // cout<<i<<j<<mn<<"kj   ";
                   dp[i][j]=1+mn; 
                    
                }
            }
        }
        // cout<<endl;
        //   for(int i=0;i<=n;i++)
        // {
        //     for(int j=0;j<=k;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[n][k];
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