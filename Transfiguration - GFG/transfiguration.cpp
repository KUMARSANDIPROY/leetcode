// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    public:
    int transfigure (string A, string B)
    {
    	// Your code goes here
    	if(A.length()!=B.length())
    	   return -1;
    	
    	int sum=0;
    	map<char,int> mp;
    	for(int i=0;i<A.length();i++)
    	{
    	    mp[A[i]]++;
    	    mp[B[i]]--;
    	}
    	
    	for(auto it: mp)
    	{
    	    if(it.second!=0)
    	       return -1;
    	}
    	
    	int i=A.length()-1;
    	int j=i;
    	int count=0;
    	while(i>=0)
    	{
    	    if(A[i]==B[j])
    	    {
    	        i--;
    	        j--;
    	    }
    	    else
    	    {
    	        count++;
    	        i--;
    	    }
    	    
    	}
    	return count;
    }
};

// { Driver Code Starts.


int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution obj;
        cout << obj.transfigure (A, B) << endl;
    }
}  // } Driver Code Ends