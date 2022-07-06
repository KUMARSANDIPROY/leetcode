// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  bool is_pallindrome(string s,int i,int j)
  {
      while(i<j)
      {
          if(s[i]!=s[j])
            return false;
          i++;
          j--;
      }
      return true;
  }
  
  void solve(string s,int idx,vector<string> temp,vector<vector<string>> &res)
  {
      if(idx==s.length())
      {
          res.push_back(temp);
          return ;
      }
      
      for(int i=idx;i<s.length();i++)
      {
          if(is_pallindrome(s,idx,i))
          {
              string st=s.substr(idx,i-idx+1);
              temp.push_back(st);
              solve(s,i+1,temp,res);
              //temp.erase(temp.begin()+temp.size()-1);
              temp.pop_back();
          }
          
      }
  }
  
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        vector<string> temp;
        vector<vector<string>> res;
        solve(S,0,temp,res);
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends