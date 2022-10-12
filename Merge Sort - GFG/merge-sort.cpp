//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int l1=m-l+1;
         int l2=r-m;
         
         int a1[l1],a2[l2];
         
         int index=l;
         for(int i=0;i<l1;i++)
         {
             a1[i]=arr[index++];
         }
         for(int i=0;i<l2;i++)
         {
             a2[i]=arr[index++];
         }
         
         int i=0,j=0;
         int idx=l;
         
         while(i<l1 && j<l2)
         {
             if(a1[i]<a2[j])
             {
                 arr[idx++]=a1[i++];
                 
             }
             else
               arr[idx++]=a2[j++];
         }
         
         
         while(i<l1)
            arr[idx++]=a1[i++];
            
          while(j<l2)
            arr[idx++]=a2[j++];
         
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        
        if(l<r)
        {
            int mid=(l+r)/2;
            
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            merge(arr,l,mid,r);
        }
        
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends