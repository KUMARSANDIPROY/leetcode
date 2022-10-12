// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here  
        set<char> s;
        for(char x:str)
           s.insert(x);
        int n=s.size();
        
        unordered_map<char,int> mp;
        mp[str[0]]++;
        
        int i=0,j=1;
        int count=1;
        int ans=INT_MAX;
        while(i<=j &&j<str.length())
        {
            if(count<n)
            {
                if(mp[str[j]]==0) count++;
                mp[str[j]]++;
                j++;
            }
            
            else if(count==n)
            {   while(count==n)
                {
                    ans=min(ans,j-i);
                    if(mp[str[i]]==1)  count--;
                    mp[str[i]]--;
                    i++;
                }
            }
        }
        while(count==n)
        {
             ans=min(ans,j-i);
             if(mp[str[i]]==1) count--;
             mp[str[i]]--;
             i++;
        }
        return ans;
        
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends