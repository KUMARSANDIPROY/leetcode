// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        int t[N+1][N+1];
        memset(t,0,sizeof(t));
        
        for(int i=0;i<N;i++)
        {
           t[i][i]=0;
        }
        
        for(int l=2;l<N;l++)
        {
            for(int i=1;i<=N-l+1;i++)
            {
                int mi=INT_MAX;
                int j=i+l-1;
                for(int k=i;k<j;k++)
                {
                    int temp=t[i][k]+t[k+1][j]+arr[i-1]*arr[k]*arr[j];
                    
                    mi=min(temp,mi);
                }
                
                t[i][j]=mi;
            }
        }
        return t[1][N-1];
        
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends