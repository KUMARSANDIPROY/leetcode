// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int solve(int ind , int prev , int A[] , int N){
       if(ind ==N) return 0;
       int not_take = 0+solve(ind+1,prev,A,N);
       int take = 0;
       if(prev == -1 or abs(A[ind]-prev)==1) take = 1 + solve(ind + 1, A[ind], A , N);
       
       return max(take , not_take);
    }
       int longestSubsequence(int N, int A[])
       {
           return solve(0,-1,A,N);
       }
        
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends