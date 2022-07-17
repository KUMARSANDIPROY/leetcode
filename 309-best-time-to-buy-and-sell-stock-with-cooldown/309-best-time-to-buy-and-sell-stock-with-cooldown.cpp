class Solution {
public:
        int solve(vector<int> &A,int N,int buy,int ind,vector<vector<int>> &dp)
    {
        if(ind>=N)  return 0;
        if(dp[ind][buy]!=-1)  return dp[ind][buy];
        
        if(buy==1)
            return dp[ind][buy]=max(-A[ind] + solve(A,N,0,ind+1,dp),
                          0    + solve(A,N,1,ind+1,dp) );
                          
        else   
            return dp[ind][buy]=max(A[ind] + solve(A,N,1,ind+2,dp),
                          0    + solve(A,N,0,ind+1,dp) );
    }
    
    int maxProfit(vector<int>& prices) {
        
        int N=prices.size();
        int ind=0;
        int buy=1;
        vector<vector<int>> dp(N,vector<int>(2,-1));
        
        return solve(prices,N,buy,ind,dp);
        
    }
};