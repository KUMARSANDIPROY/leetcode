// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int prefixStrings(int N)
	{
	    // Your code goes here
	    vector<long long> dp(N+1,0);
	    dp[0]=1;
	    dp[1]=1;
	    
	    int mod=1e9+7;
	    for(int i=2;i<=N;i++)
	    {
	        for(int j=0;j<i;j++)
	        {
	            dp[i]+=((dp[j]%mod)*(dp[i-j-1]%mod))%mod;
	        }
	    }
	    return dp[N]%mod;
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

       

        Solution ob;
        cout << ob.prefixStrings(n);
	    cout << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends