// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    void solve(string &s,int dot,string temp,vector<string> &res)
    {
        
        if(dot==4)
        {
            if(s.empty()==true)
            {
                temp.pop_back();
              //  cout<<temp<<"tmp";
               res.push_back(temp);
            }
            return;
        }
        int l1=s.length();
        for(int i=0;i<min(l1,3);i++)
        {
            string sub=s.substr(0,i+1);
            string str=s;
            if(stod(sub)<=255)
            {
                if(sub.size()>1 && sub[0]=='0') continue;
                str.erase(0,i+1);
                string temp2=temp;
                temp+=sub+'.';
                solve(str,dot+1,temp,res);
                temp=temp2;
                
            }
        }
    }
  
    vector<string> genIp(string &s) {
        // Your code here
        vector<string> res;
        int l=s.length();
        if(l<4) return res;
        if(l>12) return res;
        string temp;
        solve(s,0,temp,res);
        return res;
        
    }

};

// { Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}  // } Driver Code Ends