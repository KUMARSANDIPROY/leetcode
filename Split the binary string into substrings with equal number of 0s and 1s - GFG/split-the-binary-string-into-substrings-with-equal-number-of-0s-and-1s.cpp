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
        // int zero=0;
        // int one=0;
        // char prev=str[0];
        // if(prev=='0')
        //   zero=1;
        // else
        //   one=1;
        map<char,int> mp;
        mp['0']=0;
        mp['1']=0;
        char prev=str[0];
        mp[prev]=1;
        
        for(int i=1;i<str.length();i++)
        {
           
            if(prev==str[i])
            {
                mp[prev]++;
            }
            else if(prev!=str[i])
            {
                if(prev=='0')
                   mp['1']++;
                else
                   mp['0']++;
                   
            }
         //   cout<<i<<" "<<zero<<one<<endl;
            if(mp['0']==mp['1'])
            {
                count++;
                
                mp['0']=0;
                mp['1']=0;
               if(i==str.length()-1) break;
                prev=str[i+1];
                mp[prev]++;
                i++;
            }
        }
        if(mp['1']!=mp['0']) return -1;
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