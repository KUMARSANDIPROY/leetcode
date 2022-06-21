// { Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    //code
    sort(arr,arr+size);
    int i=0, j=size-1;
    
    for(j=size-1;j>=0;j--)
    {
        i=0;
        while(i<j && arr[i]+n<=arr[j])
        {
            if((arr[i]+n)==arr[j]) return true;
            else
                i++;
        }
    }
    return false;
    
}