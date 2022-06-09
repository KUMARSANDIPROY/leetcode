// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool ispallindrome(string str,int i,int j)
    {
        while(i<j)
        {
            if(str[i]!=str[j]) return false;
            i++;
            j--;
        }    
    }

    int solve(string str,int i,int j,vector<vector<int>> &dp)
    {
        if(i>=j) return 0;
        
        if(ispallindrome(str,i,j)) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int result=1e9;
        int left,right;
        for(int k=i;k<j;k++)
        {
            //int temp=solve(str,i,k,dp)+ solve(str,k+1,j,dp)+1;
            if(dp[i][k]!=-1) left= dp[i][k];
            else
            {
                 left=solve(str,i,k,dp);
                 dp[i][k]=left;
            }
            
            if(dp[k+1][j]!=-1) right= dp[k+1][j];
            else
            {
                 right=solve(str,k+1,j,dp);
                 dp[k+1][j]=right;
                 
            }
            int temp=left+right+1;
            
            
            result=min(result,temp);
            
        }
        return dp[i][j]=result;
    }

    int palindromicPartition(string str)
    {
        // code here
        vector<vector<int>> dp(501,vector<int>(501,-1));
        return solve(str,0,str.length()-1,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends