// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++
class Solution{
    public:
    bool solve(int i,int j,string wild,string pattern,vector<vector<int>> &dp)
    {
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;
        
        if(j<0 && i>=0)
        {
            for(int k=0;k<=i;k++)
            {
                if(wild[k]!='*')  return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(wild[i]==pattern[j] || wild[i]=='?')
           return dp[i][j]=solve(i-1,j-1,wild,pattern,dp);
           
        if(wild[i]=='*')
        {
            return dp[i][j]=solve(i,j-1,wild,pattern,dp)  || solve(i-1,j,wild,pattern,dp);
        }
        
    }
    
    bool match(string wild, string pattern)
    {
        // code here
        int m=wild.size();
        int n=pattern.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        return solve(m-1,n-1,wild,pattern,dp);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        if(ob.match(wild, pattern))
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}  // } Driver Code Ends