// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        //Write your code here
        int count=0;
        int zero=0;
        int one=0;
        char prev=str[0];
        if(prev=='0')
          zero=1;
        else
          one=1;
        
        for(int i=1;i<str.length();i++)
        {
           
            if(prev==str[i])
            {
                if(prev=='0')
                   zero++;
                else 
                   one++;
            }
            else if(prev!=str[i])
            {
                if(prev=='0')
                   one++;
                else
                  zero++;
                   
            }
         //   cout<<i<<" "<<zero<<one<<endl;
            if(zero==one)
            {
                count++;
                
               // cout<<i<<" "<<zero<<one<<endl;
               if(i==str.length()-1) break;
                prev=str[i+1];
              //  cout<<prev<<"prev   "<<endl;
                if(prev=='0')
                {
                    zero=1;
                    one=0;
                }
                else
                {
                    zero=0;
                    one=1;
                }
                i++;
            }
        }
        if(zero!=one) return -1;
        return count;
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
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends