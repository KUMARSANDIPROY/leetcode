// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int minFlips (string s)
{
    // your code here
    char even='1' , odd='0';
    int count1=0;
    
    for(int i=0;i<s.length();i++)
    {
        if(i%2==0)
        {
            if(s[i]!='1')
              count1++;
        }
        else
        {
            if(s[i]!='0')
               count1++;
        }
    }
    int count2=s.length()-count1;
    
    return min(count1,count2);
    
}