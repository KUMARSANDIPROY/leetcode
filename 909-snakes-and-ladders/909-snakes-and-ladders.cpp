class Solution {
public:
    pair<int,int> find_coordinate(int x,int n)
    {
        int r=n-(x-1)/n-1;
        int c=(x-1)%n;
        if(n%2==r%2)
            c=n-1-c;
        
        return {r,c};
            
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        queue<int> q;
        int n=board.size();
        int step=0;
        //vector<vector<bool>> visited(n,vector<int>(n,false));
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        q.push(1);
        visited[n-1][0]=true;
        
        while(!q.empty())
        {
            int l=q.size();

            
            for(int i=0;i<l;i++)
            {
                int x=q.front();
                q.pop();
                if(x==n*n) return step;

                for(int j=1;j<=6;j++)
                {
                    if(x+j>n*n) break;
                    pair<int,int> p1;
                    p1=find_coordinate(x+j,n);
                    int r=p1.first;
                    int c=p1.second;
                    
                    if(visited[r][c]==true) continue;
                    visited[r][c]=true;
                    if(board[r][c]==-1)
                        q.push(x+j);
                    else
                        q.push(board[r][c]);
                }
            
            }
                  step++;
        }
        return -1;
       
    }
};