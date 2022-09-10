class Solution {
public:
    
    int mod=1e9+7;
    int solve(vector<vector<int>> &board,int i,int j,int len,int n,vector<vector<vector<int>>> &dp)
    {
        
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]==-1)  return 0;
        if(len==n)
            return 1;
        if(dp[i][j][len]!=-1) return dp[i][j][len];
        int d1[]={-1,+1};
        int d2[]={-2,+2};
        int count=0;
        for(int p=0;p<2;p++)
        {
            for(int q=0;q<2;q++)
            {
                 count=(count+solve(board,i+d1[p],j+d2[q],len+1,n,dp))%mod;
            }
        }
         for(int p=0;p<2;p++)
        {
            for(int q=0;q<2;q++)
            {
                 count=(count+solve(board,i+d2[p],j+d1[q],len+1,n,dp))%mod;
            }
        }
        return dp[i][j][len]=count;
        
        
    }
    
    
    int knightDialer(int n) {
        
        vector<vector<int>> board(4,vector<int>(3));
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(3, vector<int>(n + 1,-1)));
        int x=1;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
                board[i][j]=x++;
        }
        board[3][0]=-1;
        board[3][1]=0;
        board[3][2]=-1;
        string s;
        int count=0;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[i][j]!=-1)
                {
                    count=(count+solve(board,i,j,1,n,dp))%mod;
                }
            }
        }
        
        
        return count;
    }
};