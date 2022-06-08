class Solution {
public:
    int solve(int m,int n,vector<vector<int>> &matrix,vector<vector<int>> &dp,int row,int col)
    {
        if(n<0 || n>=col) return 1e9;
        if(m==0) return matrix[m][n];
        if(dp[m][n]!=-1) return dp[m][n];
        
        int up=matrix[m][n]+solve(m-1,n,matrix,dp,row,col);
        int ld=matrix[m][n]+solve(m-1,n-1,matrix,dp,row,col);
        int rd=matrix[m][n]+solve(m-1,n+1,matrix,dp,row,col);
        
        return dp[m][n]=min(up,min(ld,rd));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>> dp(row,vector<int>(col,-1));
        
        int res=INT_MAX;
        for(int i=0;i<col;i++)
        {
            res=min(res,solve(row-1,i,matrix,dp,row,col));
        }
        return res;
        
    }
};