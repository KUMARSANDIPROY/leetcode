// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string s){
        // code here 
        int open=0,close=0;
        int ub=0;
        
        int ans=0;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='[')
            {   if(ub==0)
                    open++;
                else
                {
                    open++;
                    ans+=ub;
                    ub--;
                }
            }
            else if(s[i]==']')
            {
                close++;
                if(close>open)
                   ub=close-open;
            }
            
               
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
}   // } Driver Code Ends