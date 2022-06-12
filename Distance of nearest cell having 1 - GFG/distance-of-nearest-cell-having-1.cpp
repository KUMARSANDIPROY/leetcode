// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int row=grid.size();
	    int col=grid[0].size();
	    vector<vector<int>> v(row,vector<int>(col,-1));
	    queue<pair<int,int>> q;
	    
	    for(int i=0;i<row;i++)
	    {
	        for(int j=0;j<col;j++)
	        {
	            if(grid[i][j]==1)
	           {
	               
	               v[i][j]=0;
	               q.push({i,j});
	           }
	              
	        }
	    }
	    
	    while(!q.empty())
	    {
	        int i=q.front().first;
	        int j=q.front().second;
	        q.pop();
	       
	       if(i-1>=0 && v[i-1][j]==-1 && grid[i-1][j]==0)
	       {
	          //   if(i==2 && j==3) cout<<"kjsbj";
	            q.push({i-1,j});
	            v[i-1][j]=v[i][j]+1;
	         
	       }
	       
	       if(i+1<row && v[i+1][j]==-1 && grid[i+1][j]==0)
            {
                q.push({i+1,j});
                v[i+1][j]=1+v[i][j];
               
            }
             if(j+1<col && v[i][j+1]==-1 && grid[i][j+1]==0)
            {
                q.push({i,j+1});
                v[i][j+1]=1+v[i][j];
            }
             if(j-1>=0 && v[i][j-1]==-1 && grid[i][j-1]==0)
            {
                q.push({i,j-1});
                v[i][j-1]=1+v[i][j];
                
            }
            
        }
        return v;
	       
	 }
	
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends