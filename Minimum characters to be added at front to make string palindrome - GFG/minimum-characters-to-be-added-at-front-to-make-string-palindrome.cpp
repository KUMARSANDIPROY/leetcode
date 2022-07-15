// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int minChar(string str){
        //Write your code here
        int i=0,n=str.size();
        int k=n-1;
        int j=k;
        while(j>i){
            if(str[i]!=str[j]){
                k--;
                i=0;
                j=k;
            }else{
                i++;
                j--;
            }
        }
        
        return (n-1)-k;
        
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends