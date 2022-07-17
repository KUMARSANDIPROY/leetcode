class Solution {
public:
    int solve(vector<int> &prices,int n,int ind,int buy,int cap,vector<vector<vector<int>>> &dp)
    {
        if(cap==0 || ind==n) return 0;
        
        if(dp[ind][buy][cap]!=-1)  return dp[ind][buy][cap];
        
        if(buy==1)
        {
            return dp[ind][buy][cap]=max(-prices[ind] +  solve(prices,n,ind+1,0,cap,dp), 0 +  solve(prices,n,ind+1,buy,cap,dp));
        }
        else
              return dp[ind][buy][cap]=max(+prices[ind] +solve(prices,n,ind+1,1,cap-1,dp),0 +  solve(prices,n,ind+1,buy,cap,dp));
    }
    
    
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        int buy=1;
        int ind=0;
        int cap=2;
        return solve(prices,n,ind,buy,cap,dp);
    }
};