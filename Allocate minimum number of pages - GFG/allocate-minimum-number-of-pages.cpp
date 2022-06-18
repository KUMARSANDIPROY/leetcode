// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isvalid(int arr[],int n,int k,int mid)
    {
        int student=1,sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(sum>mid)
            {
                student++;
                sum=arr[i];
            }
            if(student>k) return false;
        }
        return true;        
    }
    
    int findPages(int A[], int N, int M) 
    {
        //code here
        int start=A[N-1];
        int end=0;
        for(int i=0;i<N;i++)
        {
            end+=A[i];
        }
        int res=0;
        int mid;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            
            if(isvalid(A,N,M,mid))
            {
                res=mid;
                end=mid-1;
            }
            else 
               start=mid+1;
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends