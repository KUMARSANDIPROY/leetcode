// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        
        stack<int> st;
        int k=0;
        //cout<<"hvj,h";
        for(int i=0;i<A.size();i++)
        {
            if(B[k]!=A[i])
               st.push(A[i]);
               
            else if(B[k]==A[i]) 
            {
                k++;
            }
            if(!st.empty() && B[k]==st.top())
            {
                while(!st.empty() && B[k]==st.top())
              {
                  k++;
                st.pop();
              }
            }
        }
        while(st.empty()==false)
        {
            if(B[k]!=st.top()) return 0;
            else if(B[k]==st.top())
            {
                k++;
                st.pop();
            }
        }
        return 1;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        Solution ob;
        cout<<ob.isStackPermutation(n,a,b)<<endl;
    }
    
    return 0;
}  // } Driver Code Ends