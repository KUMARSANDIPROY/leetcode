class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        
        
        if(obs[0][0]==1)  return 0;
        int m=obs.size();
        int n=obs[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        
        
        dp[0][0]=1;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0) continue;
                if(obs[i][j]==0)
                {
                    int left=0,up=0;
                    if(i-1>=0)
                        up=dp[i-1][j];
                    if(j-1>=0)
                        left=dp[i][j-1];
                    
                    dp[i][j]=left+up;
                }
            }
        }
        return dp[m-1][n-1];
    }
};