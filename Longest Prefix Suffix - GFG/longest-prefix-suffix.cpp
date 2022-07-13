// { Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
	  //  int mx=INT_MIN;
	    int n=s.size();
	    vector<int> LPS(n);
	    
	    LPS[0]=0;
	    
	   
	    int len=0,i=1;
	    
	    while(i<n)
	    {
	         if(s[len]==s[i])
	        {
	            LPS[i]=len+1;
	            //mx=max(LPS[j],mx);
	            len++;
	            i++;
	           
	        }
	        
	        else if(s[i]!=s[len])
	        {
	            if(len==0)
	           {
	               LPS[i]=0;
	               i++;
	           }
	           else
	           {
	               len=LPS[len-1];
	               
	           }
	        }
	        
	       // cout<<LPS[j]<<"  ";
	 
	    }
	    return LPS[n-1];
	   
	    
	    
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
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends