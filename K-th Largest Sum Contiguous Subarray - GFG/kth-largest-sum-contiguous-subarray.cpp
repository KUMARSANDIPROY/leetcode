// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
      vector<int> sum(N+1);
       sum[0]=0,sum[1]=Arr[0];
      
      for(int i=2;i<=N;i++)
      {
          sum[i]=Arr[i-1]+sum[i-1];
      }
      
      priority_queue<int,vector<int>,greater<int>> q;
      
      for(int i=1;i<=N;i++)
      {
          
          for(int j=i;j<=N;j++)
          {
              int res=sum[j]-sum[i-1];
              q.push(res);
              
              if(q.size()>K) 
                 q.pop();
                 
                   
          }
      }
      return q.top();
    }
};

// { Driver Code Starts.

int main(){
    
    int T;
    cin>>T;
    while(T--){
        int N,K;
        cin>>N;
        cin>>K;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        int ans=ob.kthLargest(Arr,N,K);
        cout<<ans<<endl;
    }
    return 0;
}  // } Driver Code Ends