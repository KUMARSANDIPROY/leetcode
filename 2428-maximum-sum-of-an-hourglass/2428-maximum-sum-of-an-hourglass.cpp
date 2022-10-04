class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
            int mx = 0;
        int sum = 0;
        for (int row = 0; row <= grid.size()-3; row++) {       
            for (int col = 0; col <= grid[0].size()-3; col++) { 
                sum = grid[row][col] +grid[row][col+1] +grid[row][col+2] +grid[row+1][col+1] +grid[row+2][col] +grid[row+2]                   [col+1] +grid[row+2][col+2];
                mx = max(sum, mx); 
        }
    }
    
    return mx;
    }
};