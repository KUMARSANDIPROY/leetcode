// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<pair<int,int>>q;
        int row=grid.size();
        int col=grid[0].size();
          vector<vector<int>> v(row,vector<int>(col,-1));
        int fresh=0,countfresh=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==2)
                 {
                     q.push({i,j});
                     v[i][j]=0;
                 }
                 if(grid[i][j]==1)
                 {
                     fresh++;
                 }
            }
        }
        int ans=0;
        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            
            if(i-1>=0 && v[i-1][j]==-1 && grid[i-1][j]==1)
            {
                q.push({i-1,j});
                v[i-1][j]=1+v[i][j];
                ans=max(ans,v[i-1][j]);
                countfresh++;
            }
            
           if(i+1<row && v[i+1][j]==-1 && grid[i+1][j]==1)
            {
                q.push({i+1,j});
                v[i+1][j]=1+v[i][j];
                ans=max(ans,v[i+1][j]);
                countfresh++;
            }
             if(j+1<col && v[i][j+1]==-1 && grid[i][j+1]==1)
            {
                q.push({i,j+1});
                v[i][j+1]=1+v[i][j];
                ans=max(ans,v[i][j+1]);
                countfresh++;
            }
             if(j-1>=0 && v[i][j-1]==-1 && grid[i][j-1]==1)
            {
                q.push({i,j-1});
                v[i][j-1]=1+v[i][j];
                ans=max(ans,v[i][j-1]);
                countfresh++;            
                
            }
            
        }
        if(countfresh<fresh) return -1;
        return ans;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends