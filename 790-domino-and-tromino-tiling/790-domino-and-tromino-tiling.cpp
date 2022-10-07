class Solution {
public:
    int m=1e9+7;
    int numTilings(int n) {
        vector<int> dp(n+1);
        if(n==1)  return 1;
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        
        for(int i=3;i<=n;i++)
        {
            dp[i]=(2*dp[i-1]%m + dp[i-3]%m)%m;
        }
        return dp[n];
    }
};