// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
     
    bool isValid(int i, int j, int n, vector<vector<int>>&visited){
        if(i>=0 && i<n && j>=0 && j<n && visited[i][j] == 0){
            return true;
        }
        return false;
    }
    
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	     // Code here
	    int n = N;
	    int tx = TargetPos[0]-1, ty = TargetPos[1]-1;
	    int x1 = KnightPos[0]-1, y1 = KnightPos[1]-1;
	    
	    if(x1 == tx && y1 == ty) return 0;
	    
	    vector<vector<int>>visited(n, vector<int>(n, 0));
	    
	    queue<pair<int, int>>q;
	    q.push({x1, y1});
	    visited[x1][y1] = 0;
	    
	 
	       
	           while(!q.empty()) {
	            pair<int,int>p = q.front();
	            q.pop();
	       
	            int xx = p.first;
	            int yy = p.second;
	            
	            int ax[8] = {1, 1, -1, -1, 2, -2, 2, -2};
	            int ay[8] = {2, -2, 2, -2, 1, 1, -1, -1};
	            
	            for(int i=0; i<8; i++){
	                int nx = xx + ax[i];
	                int ny = yy + ay[i];
	                
	               if(nx == tx && ny == ty) return visited[xx][yy]+1;
	                
	                if(isValid(nx, ny, n, visited)){
	                    visited[nx][ny] = visited[xx][yy]+1;
	                    q.push({nx, ny});
	                }
	            }
	           
	           
	        }
	   
	    
	    
	    return visited[tx][ty];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends