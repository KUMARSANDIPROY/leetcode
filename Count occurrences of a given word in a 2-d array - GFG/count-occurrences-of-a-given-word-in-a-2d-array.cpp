//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int count=0;
     bool solve(vector<vector<char>> &board,string word,int i,int j,int idx,vector<vector<int>> vis)
    {
        int row=board.size();
        int col=board[0].size();
        
        if(idx==word.size())   
        {
            count++;
            return true;
        }
        //if(i<0 || i>=row || j<0 || j>=col)  return false;
        
       // vis[i][j]=1;
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        
        for(int k=0;k<4;k++)
        {
                if(i+dx[k]>=0 && i+dx[k]<row && j+dy[k]>=0 && j+dy[k]<col &&  word[idx]==board[i+dx[k]][j+dy[k]]  && vis[i+dx[k]][j+dy[k]]==0 )
                {
                    vis[i+dx[k]][j+dy[k]]=1;
                    (solve(board,word,i+dx[k],j+dy[k],idx+1,vis));
                   
                      
                    vis[i+dx[k]][j+dy[k]]=0;  
                }
        }
           
           return false;
        
    }
    
    
    int findOccurrence(vector<vector<char> > &board, string word){
        
         int row=board.size();
        int col=board[0].size();
        //int count=0;
        vector<vector<int>> vis(row+1,vector<int>(col+1,0));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(word[0]==board[i][j])
                {
                   //  cout<<i<<"  "<<j<<endl;
                    vis[i][j]=1;
                    (solve(board,word,i,j,1,vis));
                   
                    vis[i][j]=0;   
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<vector<char> > mat(R);
        for (int i = 0; i < R; i++) {
            mat[i].resize(C);
            for (int j = 0; j < C; j++) cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout<<obj.findOccurrence(mat,target)<<endl;
    }
}

// } Driver Code Ends