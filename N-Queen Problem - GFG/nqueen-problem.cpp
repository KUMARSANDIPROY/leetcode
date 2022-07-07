// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool is_safe(vector<vector<int>> chess,int n,int row,int col)
     {   
         //if(row==1 && col==2)
    //       cout<<"jsd12  ";
        
        for(int i=col-1;i>=1;i--)
        {   
            if(chess[row][i]==1) return false;
        }
        
        for(int i=row-1,j=col-1; i>=1 && j>=1;i--,j--)
        {
            if(chess[i][j]==1) return false;
        }
        for(int i=row+1,j=col-1;i<=n && j>=1;i++,j--)
        {
            if(chess[i][j]==1) return false;
        }
        return true;
    }

    void solve(int n,vector<vector<int>> chess,int col,vector<vector<int>> &res,vector<int> temp)
    {
        if(col==n+1)
        {
            res.push_back(temp);
            return;
        }
        
        for(int row=1;row<=n;row++)
        {
            if(is_safe(chess,n,row,col))
            {
                chess[row][col]=1;
                temp.push_back(row);
                solve(n,chess,col+1,res,temp);
                temp.pop_back();
                chess[row][col]=0;
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> chess(n+1,vector<int>(n+1,0));
        int col=1;
        vector<vector<int>> res,res1;
        vector<int> temp;
        solve(n,chess,col,res,temp);
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends