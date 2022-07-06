// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
   void solve(string A, vector<string> &B,int idx,string str,vector<string> &res)// same as pallindrome partitioning
    {
        // if(idx==A.length())
        //   return ;
         
        for(int i=idx;i<A.length();i++)
        {
            string temp=str;
            string sub=A.substr(idx,i-idx+1);
            if(find(B.begin(),B.end(),sub)!=B.end())
            {
                if(i==A.length()-1)
                {
                    str+=sub;
                    res.push_back(str);
                    return ;
                }
                else
                {
                   str+=sub +" ";
                }
             
               solve(A,B,i+1,str,res);
               str=temp;
                
            }
        }
         
    
    }

    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        vector<string> res;
        string str="";
        solve(s,dict,0,str,res);
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends