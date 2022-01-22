class Solution {
public:
    void dfs(vector<vector<char>> &board,int i,int j,int r,int c)
    {
        if(i>=r ||i<0 || j>=c || j<0) return;
        if(board[i][j]=='X' || board[i][j]=='1') return;
        // cout<<i<<j<<"bjb  ";
        
        board[i][j]='1';
        dfs(board,i-1,j,r,c);
        dfs(board,i+1,j,r,c);
        dfs(board,i,j-1,r,c);
        dfs(board,i,j+1,r,c);
    }
    
    void solve(vector<vector<char>>& board) {
        
        int r=board.size();
        int c=board[0].size();
        
        for(int i=0;i<r;i++)
        {
           
           dfs(board,i,0,r,c);
           dfs(board,i,c-1,r,c); 
        }
        for(int i=0;i<c;i++)
        {
           dfs(board,0,i,r,c);
           dfs(board,r-1,i,r,c);
        }
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j]=='1')
                    board[i][j]='O';
                else if(board[i][j]=='O')
                    board[i][j]='X';
                    
            }
        }
        
    }
};