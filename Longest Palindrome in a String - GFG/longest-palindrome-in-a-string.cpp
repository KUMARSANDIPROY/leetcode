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
      
        int start=0,maxlen=1;
       
         
        for(int i=0;i<l;i++)//fiiling the diagonal elements with 1;
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
                 if(maxlen<2)  //for taking the first pallindromne of length 2
                    start=i;
                 maxlen=2;
                
             }
        }
        
        
        for(int k=3;k<=l;k++)// k=pallindrome length;
        {
            for(int i=0;i<l-k+1;i++)
            {
                int j=i+k-1;

                
                if(s[i]==s[j] && D[i+1][j-1]==1)//codition
                {
                    D[i][j]=1;
                    if(j-i+1>maxlen)
                    {
                        maxlen=j-i+1;
                    
                        start=i;
                     
                    }
                }
                  
            }
           
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