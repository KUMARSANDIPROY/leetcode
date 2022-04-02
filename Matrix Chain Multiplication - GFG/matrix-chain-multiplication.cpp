// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public: 
    int  t[1001][1001];

    int solve(int arr[],int i,int j)
    {
        if(i>=j) return 0;
        int mi=INT_MAX;
        if(t[i][j] !=-1) return t[i][j];
        for(int k=i;k<j;k++)
        {
           
          
            int temp=solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
            
            mi=min(mi,temp);
        }
       return  t[i][j]=mi;
        
    }

    int matrixMultiplication(int N, int arr[])
    {
        // code here
        if(N==1) return 0;
          memset(t,-1,sizeof(t));
          int res=solve(arr,1,N-1);
          return res;
        
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