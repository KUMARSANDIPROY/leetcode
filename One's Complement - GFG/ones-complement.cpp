// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 

 // } Driver Code Ends
class Solution{
public:
    int onesComplement(int N){
        //code here
        int c=0,n=N;
        
       while(N!=0)
       {
        c++;
        N/=2;
       }
       int x=(1<<c)-1;
       return x^n;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        Solution ob;
        cout<<ob.onesComplement(n)<<"\n";
    }
}  // } Driver Code Ends