// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int nCr(int n, int r){
        // code here
        int mod=1e9+7;
        if(r>n) return 0;
        
        vector<int> dp(r+1,0);
        dp[0]=1;
        
        for(int i=1;i<=n;i++)
        {
            vector<int> temp=dp;
            for(int j=1;j<=min(r,i);j++)
            {
                
                temp[j]=(dp[j-1]+dp[j])%mod;
              //  cout<<j<<dp[j]<<" ";
            }
            dp=temp;
           // cout<<endl;
        }
        return dp[r];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends