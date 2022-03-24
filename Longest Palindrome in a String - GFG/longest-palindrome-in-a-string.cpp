// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        // code here
        string s=S;
        int l=s.length();
        int D[l+1][l+1];
       // string res="";
        int start=0,maxlen=1;
       
          // cout<<"jhsvdcjh";
        for(int i=0;i<l;i++)
        {
            for(int j=0;j<l;j++)
            {
                if(i==j)
                  D[i][j]=1;
                else
                 D[i][j]=0;
            }
        }
     
       
         for(int i=0;i<l-1;i++)
        {
            if(i<l-1 &&s[i]==s[i+1])
             {
                 D[i][i+1]=1;
                 if(maxlen<2)  start=i;
                 maxlen=2;
                 //pl=s.substr(i,2);
             }
        }
        
        
        for(int k=3;k<=l;k++)
        {
            for(int i=0;i<l-k+1;i++)
            {
                int j=i+k-1;
               // cout<<i<<" ";
                
                if(s[i]==s[j] && D[i+1][j-1]==1)
                {
                    D[i][j]=1;
                    if(j-i+1>maxlen)
                    {
                        maxlen=j-i+1;
                        //pl=s.substr(i,k);
                      // cout<<k<<pl<<" ";
                        start=i;
                     
                    }
                }
                  
            }
            //cout<<endl;
        }

        return s.substr(start,maxlen);
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends