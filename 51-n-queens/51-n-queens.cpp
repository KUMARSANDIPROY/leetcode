class Solution {
public:
    bool is_safe(vector<string> board,int row,int col)
    {
        int temp_row=row,temp_col=col;
         
        
        while(row>=0 && col>=0)
        {
           if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        col=temp_col;
        row=temp_row;
        while(col>=0)
        {
           if(board[row][col]=='Q') return false;
        
             col--;
        }
           col=temp_col;
           row=temp_row;

        
         while(row<board.size() && col>=0)
        {
           if(board[row][col]=='Q') return false;
            row++;
            col--; 
            
        }
        
        
        
    return true;
        
        
    }
    
    
    void solve(vector<string> board,int col)
    {
        
        
        if(col==board.size())
        {
            res.push_back(board);
            return;
        }
   
        for(int row=0;row<board.size();row++)
        {
            if(is_safe(board,row,col))
            {
                 board[row][col]='Q';
                 solve(board,col+1);
                 board[row][col]='.';
            }
        }
        
        
    }
    
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        
      
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
           board[i]=s;
        }
        
        solve(board,0);
        return res;
        
    }
};