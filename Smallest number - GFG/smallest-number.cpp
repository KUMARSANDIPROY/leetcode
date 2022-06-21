// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
        // code here 
        string res="";
        if(9*D<S) return "-1";
        
        for(int i=D-1;i>=0;i--)
        {
            if(S>9)
            {
                res='9' +res;
                S-=9;
            }
            else
            {
                if(i==0)
                {
                  res=to_string(S) + res;
                  break;
                 }
                 else
                 {
                     res=to_string(S-1)+res;
                     i--;
                     while(i>0)
                     {
                         res='0' +res;
                         i--;
                     }
                     res='1'+res;
                 }
                  
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
}   // } Driver Code Ends