// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> st;
        string s=x;
    
        for(int i=0;i<s.length();i++)
        {
          // cout<<"jsddc ";
            if(st.empty() && (s[i]==')' || s[i]=='}' || s[i]==']')) return false;
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
             {
               //  cout<<"jjgvhkjb,jddc ";
                 st.push(s[i]);
                  //cout<<st.top()<<" ";
                 continue;
             }
               //  cout<<st.top()<<" ";
             
             if(s[i]==')')
             {
                 // cout<<"jsddc ";
                 if(st.top()!='(')
                    return false;
                    
                 else 
                    st.pop();
                    
             }
              if(s[i]=='}')
             {
                 if(st.top()!='{')
                    return false;
                    
                 else 
                    st.pop();
                    
             }
             if(s[i]==']')
             {
                // cout<<"jsddc ";
                 if(st.top()!='[')
                    return false;
                    
                 else 
                    st.pop();
                    
             }
          
            
        }
        if(st.empty()) 
           return true;
        else return false;   
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends