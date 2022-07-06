// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> res;
    void solve(vector<vector<int>> &m, int n,string s,int i,int j,vector<vector<int>> vis)
    {
        if(i<0 || i>=n || j<0 || j>=n || m[i][j]==0 || vis[i][j]==1)
        {
            return ;
        }
        if(i==n-1&& j==n-1)
        {
            res.push_back(s);
            return ;
        }
         vis[i][j]=1;
        string s1=s;
        s1+="U";
      
        solve(m,n,s1,i-1,j,vis);
        
        string s2=s;
        s2+="D";
        solve(m,n,s2,i+1.,j,vis);
        
        string s3=s;
        s3+="L";
        solve(m,n,s3,i,j-1,vis);
        
        string s4=s;
        s4+="R";
        solve(m,n,s4,i,j+1,vis);
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        string s="";
        
        vector<vector<int>> vis(n,vector<int>(n,0));
        solve(m,n,s,0,0,vis);
        return res;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends