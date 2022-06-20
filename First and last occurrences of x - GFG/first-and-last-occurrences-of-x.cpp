// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int> res1;
    
    
    int res=-1;
    int start=0 , end=n-1;
    int mid;
    while(start<=end)
    {
        mid=start+(end-start)/2;
        if(x==arr[mid])
        {
            res=mid;
            end=mid-1;
        }
        else if(x<arr[mid])
        {
            end=mid-1;
            
        }
        else start=mid+1;
    }
    int x1=res;
    
    res=-1;
    start=0 ;
    end=n-1;
    //int mid;
    while(start<=end)
    {
        mid=start+(end-start)/2;
        if(x==arr[mid])
        {
            res=mid;
            start=mid+1;
        }
        else if(x<arr[mid])
        {
            end=mid-1;
            
        }
        else start=mid+1;
    }
    int y=res;
    
    res1.push_back(x1);
    
    res1.push_back(y);
    return res1;
    
}


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends