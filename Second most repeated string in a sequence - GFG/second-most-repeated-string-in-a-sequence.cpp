// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        map<string,int> mp;
        int mx=0;
        string max_str;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
            if(mx<mp[arr[i]])
            {
                mx=mp[arr[i]];
                max_str=arr[i];
            }
        }
        
        mp.erase(max_str);
        
        int mx2=0;
        string max_str2;
        for(int i=0;i<n;i++)
        {
            
            if(mx2<mp[arr[i]])
            {
                mx2=mp[arr[i]];
                max_str2=arr[i];
            }
        }
        return max_str2;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends