// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int minSubset(vector<int> &Arr,int N){
       sort(Arr.begin(),Arr.end());
       
       long long int sum1=0,sum2=0,i=0,j=N,iflag=1,jflag=1;
       //cout<<Arr[N-1];
       while(i<j)
       {
          
          if(iflag==1)
             sum1+=Arr[i];
          else if(jflag==1)
              sum2+=Arr[j];
          // cout<<i<<j<<" "<<sum1<<sum2<<endl;
          if(sum1<sum2)
          {
              i++;
              jflag=0;
              iflag=1;
              continue;
          }
          else 
          {
              j--;
              jflag=1;
              iflag=0;
              continue;
              
          }
          
       }
      //cout<<j<<" ";
       return N-j;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        cout<<ob.minSubset(Arr,N)<<endl;
    }
    return 0;
}  // } Driver Code Ends