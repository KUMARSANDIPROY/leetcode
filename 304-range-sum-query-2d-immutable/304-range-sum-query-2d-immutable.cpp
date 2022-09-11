class NumMatrix {
public:
    vector<vector<int>> res;
    NumMatrix(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        
        res.resize(row,vector<int>(col,0));
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                res[i][j]=matrix[i][j];
                if(i-1>=0)
                    res[i][j]+=res[i-1][j];
                if(j-1>=0)
                    res[i][j]+=res[i][j-1];
                if(i-1>=0 && j-1>=0)
                    res[i][j]-=res[i-1][j-1];
                
                //cout<<res[i][j]<<"  ";
            }
          //  cout<<endl;
        }
        
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int ans=res[row2][col2];
        
        cout<<ans<<"  ";
        if(row1-1>=0)
            ans-=res[row1-1][col2];
        cout<<ans<<"  ";
        if(col1-1>=0)
            ans-=res[row2][col1-1];
        cout<<ans<<"  ";
        if(col1-1>=0 && row1-1>=0)
            ans+=res[row1-1][col1-1];
        
        cout<<ans<<endl;
        return ans;
    }
    
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */