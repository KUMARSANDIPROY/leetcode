// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++
class Solution{
    public:
    bool solve(int i,int j,string wild,string pattern)
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
        
        if(wild[i]==pattern[j] || wild[i]=='?')
           return solve(i-1,j-1,wild,pattern);
           
        if(wild[i]=='*')
        {
            return solve(i,j-1,wild,pattern)  || solve(i-1,j,wild,pattern);
        }
        
    }
    
    bool match(string wild, string pattern)
    {
        // code here
        int m=wild.size();
        int n=pattern.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        return solve(m-1,n-1,wild,pattern);
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