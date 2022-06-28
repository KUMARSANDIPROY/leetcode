// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        // code here
        long long dp[n+1];
        int mod=1e9+7;
        
        for(int i=0;i<=n;i++)
        {
            if(i<=2)
               dp[i]=i;
               
            else
            {
                dp[i]=((dp[i-1])%mod+(((i-1)%mod)*(dp[i-2])%mod))%mod;
            }
        }
        return dp[n];
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends