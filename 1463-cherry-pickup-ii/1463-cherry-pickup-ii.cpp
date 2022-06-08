class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<vector<int>>> dp(row,vector<vector<int>>(col,vector<int>(col,0)));
        
        for(int c1=0;c1<col;c1++)
        {
            for(int c2=0;c2<col;c2++)
            {
                if(c1==c2)  dp[row-1][c1][c2]=grid[row-1][c1];
                else  dp[row-1][c1][c2]=grid[row-1][c1]+grid[row-1][c2];
            }
         }
        
        for(int r=row-2;r>=0;r--)
        {
            for(int c1=0;c1<col;c1++)
            {
                for(int c2=0;c2<col;c2++)
                {
                      
                    int maxi=0;
                   
                    for(int i=-1;i<=1;i++)
                    {

                        for(int j=-1;j<=1;j++)
                        {
                     
                            if(c1==c2 && c1+i<col && c1+i>=0 && c2+j<col && c2+j>=0) 
                                maxi=max(maxi,grid[r][c1]+dp[r+1][c1+i][c2+j]);
                            
                            else if(c1+i<col && c1+i>=0 && c2+j<col && c2+j>=0)
                                maxi=max(maxi,grid[r][c1]+grid[r][c2]+dp[r+1][c1+i][c2+j]);
                            
                              
                        }
                    }

                     dp[r][c1][c2]=maxi;
                    
        
                }
            }
        }
        return dp[0][0][col-1];
        
    }
};