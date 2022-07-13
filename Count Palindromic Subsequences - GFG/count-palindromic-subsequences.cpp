// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
       //Your code here
       int mod=1e9+7;
       int l=str.length();
       
       vector<vector<long long>> dp(l,vector<long long>(l));
       
       for(int g=0;g<l;g++)
       {
           for(int i=0,j=g;j<l;j++,i++)
           {
                if(g==0)
                   dp[i][j]=1;
                else if(g==1)
                   dp[i][j]= str[i]==str[j] ? 3 : 2 ;
                
                else
                {
                    if(str[i]==str[j])
                       dp[i][j]=(((dp[i][j-1]) + (dp[i+1][j])) + 1)%mod;
                    
                    else
                       dp[i][j]=(((dp[i][j-1]) + (dp[i+1][j])) -dp[i+1][j-1] + mod)%mod;
                }
           }
       }
       return (dp[0][l-1])%mod;
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends