// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
         int curj=0,maxj=0,jump=0;
         for(int i=0;i<n-1;i++)
         {
             maxj=max(maxj,arr[i]+i);
            // cout<<i<<curj<<" ";
            
             if(i==curj)
             {
                 curj=maxj;
                 jump++;
             }
             if(i==curj) return -1;
           
         }
         return jump; 
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends