class Solution {
public:
    int solve(int r,int c1,int c2,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp,int row,int col)
    {
      
       
        if(c1<0 || c1>=col || c2<0 || c2>=col) return -1e9;
  
        if(r==row-1)
        {
            if(c1==c2) return grid[r][c1];
            else return grid[r][c1]+ grid[r][c2];
        }
                if(dp[r][c1][c2]!=-1) return dp[r][c1][c2];
        
        int maxi=0;
        for(int i=-1;i<=1;i++)
        {
            
            for(int j=-1;j<=1;j++)
            {
                if(c1==c2) 
                {
                    maxi=max(maxi,grid[r][c1]+solve(r+1,c1+i,c2+j,grid,dp,row,col));
                }
                else
                    maxi=max(maxi,grid[r][c1]+grid[r][c2]+solve(r+1,c1+i,c2+j,grid,dp,row,col));
            }
        }
           
        return dp[r][c1][c2]=maxi;
        
        
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<vector<int>>> dp(row, vector<vector<int>>(col,vector<int>(col,-1))); 
    
        return solve(0,0,col-1,grid,dp,row,col);
    }
};