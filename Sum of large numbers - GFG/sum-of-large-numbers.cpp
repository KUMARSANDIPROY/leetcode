// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
	public:
   	string add(string str1, string str2){
   	    // Code here
   	    if(str1.length()<str2.length())
   	      swap(str1,str2);
   	      
   	    int l1=str1.size();
   	    int l2=str2.length();
   	    
   	    reverse(str1.begin(),str1.end());
   	    reverse(str2.begin(),str2.end());
   	    
   	    string res="";
   	    
   	    int carry=0;
   	    
   	    for(int i=0;i<l2;i++)
   	    {
   	        int x=((str1[i]-'0') + (str2[i]-'0') + carry);
   	        res+=to_string(x%10);
   	        carry=x/10;
   	    }
   	    
   	    for(int i=l2;i<l1;i++)
   	    {
   	        int x=(str1[i]-'0') + carry;
   	        carry=x/10;
   	        res+=to_string(x%10);
   	    }
   	    if(carry)
   	      res+=to_string(carry);
   	    reverse(res.begin(),res.end());
   	    return res;
   	}    
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s1, s2;
		cin >> s1 >> s2;
		Solution ob;
		string ans = ob.add(s1, s2);
		cout << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends