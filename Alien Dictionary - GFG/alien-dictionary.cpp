// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string res="";
    
    
    void dfs( map<char,list<char>> adj,map<char,int> &visited,char node)
    {
        visited[node]=1;
        
        for(char i: adj[node])
        {
            if(visited[i]!=1)
               dfs(adj,visited,i);
        }
        res.push_back(node);
    }
    
    string findOrder(string dict[], int N, int K) {
        //code here
        // cout<<"dsbcnbc ";
        //vector<vector<char> > adj[];
        map<char,list<char>> adj;
        set<char> s;
      
        for(int i=0;i<N-1;i++)
        {
            int l=min(dict[i].size(),dict[i+1].size());
            for(int j=0;j<l;j++)
            {
                if(dict[i][j]==dict[i+1][j]) 
                  continue;
                
                else
                {
                    adj[dict[i][j]].push_back(dict[i+1][j]);
                    s.insert(dict[i][j]); 
                    s.insert(dict[i+1][j]);
                    break;
                }
            }
        }
        
        map<char,int> visited;
        for(char c:s)
        {
            visited[c]=0;
        }
        for(char c:s)
        {
            if(visited[c]!=1)
              dfs(adj,visited,c);
        
        }
       
        reverse(res.begin(),res.end());
        return res;
        
        
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends