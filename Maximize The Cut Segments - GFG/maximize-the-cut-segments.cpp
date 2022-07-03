// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int solve(int n,int x,int y,int z,vector<int> &dp)
    {
        if(n<0) return INT_MIN;
        if(n==0)
          return 0;
        if(dp[n]!=-1) return dp[n];
        int c1=0,c2=0,c3=0;
        c1=solve(n-x,x,y,z,dp);
        c2=solve(n-y,x,y,z,dp);
        c3=solve(n-z,x,y,z,dp);
        int result=max(c1,max(c2,c3));
        if(result==INT_MIN)
            return dp[n]=INT_MIN;
        else 
            return dp[n]=1+result;
    }
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int> dp(n+1,-1);
        int count=0;
        int res=solve(n,x,y,z,dp);
        if(res==INT_MIN)
         return 0;
        else return res; 
        
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends