// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	
	   bool static my_compare(string a, string b)
{
    // Check if a string is present as
    // prefix in another string, then
    // compare the size of the string
    // and return the larger size
   /* if (a.compare(0, b.size(), b) == 0
        || b.compare(0, a.size(), a) == 0)
 
        return a.size() > b.size();
 
    // Else return lexicographically
    // smallest string
    else*/
        return a < b;
}
	
	    void solve(string S, string op)
	    {
	        if(S.length()==0)
	        {
	            res.push_back(op);
	            return;
	        }
	 /*       if(S.length()==1)
	        {
	            op+=S[0];
	            res.push_back(op);
	            return;
	        }*/
	        
	        for(int i=0;i<S.length();i++)
	        { //cout<<"op"<<op<<" ";
	            string s1=op;
	            op+=S[i];
	           // cout<<"op"<<op<<" ";
	            string temp=S;
	            temp.erase(i,1);
	           // cout<<"t"<<temp<<" "; 
	            solve(temp,op);
	            op=s1;
	            
	        }
	    }
	
	    vector<string> res;
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    string op="";
		    
		    for(int i=0;i<S.length();i++)
		    {
		        op=S[i];
		        string temp=S;
		        temp.erase(i,1);
		       // cout<<"t"<<temp<<" ";
		        solve(temp,op);
		    }
		      sort(res.begin(), res.end(), my_compare);

		    
		    	return res;
		}
	
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends