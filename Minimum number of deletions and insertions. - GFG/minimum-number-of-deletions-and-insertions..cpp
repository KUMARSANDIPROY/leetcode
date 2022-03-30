// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	 int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        int t[x+1][y+1];
        
        for(int i=0;i<=x;i++)
        {
            for(int j=0;j<=y;j++)
            {
                if(i==0 || j==0)
                   t[i][j]=0;
                   
            }
        }
        
        for(int i=1;i<=x;i++)
        {
            for(int j=1;j<=y;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    t[i][j]=1+t[i-1][j-1];
                    
                }
                else
                {
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[x][y];
        
    }
	
	
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int l1=str1.length(),l2=str2.length();
	    int l=lcs(l1,l2,str1,str2);
	    return l1+l2-2*l;
	    
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends