// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
        // code here
        if(M>=N) return -1;
        int total=S*M;
        int rqd=ceil(double(total)/(double)N);
        if(rqd<7) return rqd;
        
        else if(rqd>=7)
        {
            if(7*M>6*N) return -1;
            else return rqd;
        }
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}  // } Driver Code Ends