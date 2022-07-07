// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku.
    bool is_valid(int grid[N][N],int row,int col,int key)
    {
       
        for(int i=0;i<N;i++)
        {
            if(grid[row][i]==key)
               return false;
        }
        for(int i=0;i<N;i++)
        {
            if(grid[i][col]==key)
               return false;
        }
         
        int sr=(row/3)*3;
        int sc=(col/3)*3;
        
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(grid[sr+i][sc+j]==key)
                return false;
            }
        }
      
        
        return true;
        
    }
    
    bool solve(int grid[N][N],int row,int col)
    {
       // cout<<row<<col<<endl;
        if(row==N)
        {
         // cout<<"stop  ";
           return true;
        } 
       
        int next_row,next_col;
        if(col==N-1)
        {
            next_row=row+1;
            next_col=0;
        }
        else
        {
            next_row=row;
            next_col=col+1;
        }
        if(grid[row][col]!=0)
         {
            return solve(grid,next_row,next_col);
              
         }
        
        else if(grid[row][col]==0)
        {   
            for(int i=1;i<=9;i++)
            {
                if(is_valid(grid,row,col,i))
                {
                    grid[row][col]=i;
                     
                    if(solve(grid,next_row,next_col))
                        return  true;
                    grid[row][col]=0;
                }
            }
        }
      //  cout<<row<<" "<<col<<" bvakjv  "<<endl;;
        return false;
    }
    
    bool SolveSudoku(int grid[N][N])  
    { 
        
        return solve(grid,0,0);
        
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0;i<N;i++)
        {
            for(int j=0; j<N;j++)
            {
                cout<<grid[i][j]<<" ";
            }
        }
        
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends