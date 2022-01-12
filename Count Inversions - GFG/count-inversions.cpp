// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int count=0;
    
    void merge(long long arr[],int left,int right )
    {
        int mid=left+(right-left)/2;
        int l1=mid-left+1;
        int l2=right-mid;
        long long first[l1],second[l2];
        int index=left;
        for(int i=0;i<l1;i++)
           first[i]=arr[index++];
           
        for(int i=0;i<l2;i++)
           second[i]=arr[index++];
        int i=0,j=0;
        index=left;  
        while(i<l1 && j<l2)
        {
            if(first[i]<=second[j])
               {
                   arr[index++]=first[i++];
                   
               }
            else 
              {
                 // cout<<index<<l2<<"y ";
                  arr[index++]=second[j++];
                  count+=l1-i;
              }
               
               
        }
        while(i<l1)
           arr[index++]=first[i++];
        while(j<l2)
           arr[index++]=second[j++];
        
    }
    
    void merge_sort(long long arr[],int left,int right)
    {
        
       
            if(left>=right)  
               return ;
            int mid=left+(right-left)/2;
            merge_sort(arr,left,mid);
            merge_sort(arr,mid+1,right);
            merge(arr,left,right);
            
            
        
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        merge_sort(arr,0,N-1);
        return count;
    }
    

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends