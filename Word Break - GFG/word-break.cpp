// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    bool solve(string A, vector<string> &B,int idx)// same as pallindrome partitioning
    {
        if(idx==A.length())
           return true;
         
        for(int i=idx;i<A.length();i++)
        {
            string sub=A.substr(idx,i-idx+1);
            if(find(B.begin(),B.end(),sub)!=B.end())
            {
               
               // if(i==A.length()-1) return true;
                if(solve(A,B,i+1))
                {
                  
                   return true;
                }
            }
        }
         
        return false;
    }

    int wordBreak(string A, vector<string> &B) {
        //code here
        
        return solve(A,B,0);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends