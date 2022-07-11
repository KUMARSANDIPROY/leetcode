// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    // Your code goes here
	    int count=0;
	    int res=-1;
	    
	    for(int i=0;i<S.length();i++)
	    {
	        if(S[i]=='1' && count==0) continue;
	        
	        else if(S[i]=='1' && count>0) 
	          count--;
	        else if(S[i]=='0')
	        {
	            count++;
	            res=max(res,count);
	        }
	    }
	    return res;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends