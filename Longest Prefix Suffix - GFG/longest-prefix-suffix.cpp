// { Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	 
	    int n=s.size();
	    vector<int> LPS(n);
	    
	    LPS[0]=0;
	    int len=0,i=1;
	    
	    while(i<n)
	    {
	         if(s[len]==s[i])
	        {
	            LPS[i]=len+1;
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
	    }
	   //for(int i:LPS)
	   //  cout<<i<<" ";
	    
	   //cout<<endl;  
	    
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