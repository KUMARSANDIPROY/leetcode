class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        
        int r=matrix.size();
        int c=matrix[0].size();
        int i=0,j=c-1;
        while(i<r && j>=0)
        {
            if(target==matrix[i][j])
                break;
            if(matrix[i][j]>target)
                j--;
            else if(matrix[i][j]<target)
                i++;
        }
    
        if(i<r && j>=0)
            return true;
        else return false;
    }
};