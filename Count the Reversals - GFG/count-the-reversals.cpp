// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev (string s)
{
    // your code here
    int l=s.length();
    
    if(l%2==1) return -1;
    
    stack<char> st;
    for(int i=0;i<l;i++)
    {
        if(st.empty())
        {
            st.push(s[i]);
        }
        else
        {
            if(s[i]=='}' && st.top()=='{')
               st.pop();
            
            else
               st.push(s[i]);
        }
    }
    int count=0;
    while(!st.empty())
    {
        char x=st.top();
        st.pop();
        char y=st.top();
        st.pop();
        if((x=='{' && y=='{') || (x=='}' && y=='}'))
           count++;
        else if(x=='{' && y=='}')
           count+=2;
    }
    return count;
}