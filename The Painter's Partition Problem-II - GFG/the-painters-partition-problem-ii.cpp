//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    int solve(int arr[],long long mid,int n)
    {
        long long count=1;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(sum>mid)
            {
                sum=arr[i];
                count++;
            }
        }
        return count;
    }
  
  
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
       int maxi=0;
       long long sum=0;
       
       for(int i=0;i<n;i++)
       {
           sum+=arr[i];
           maxi=max(arr[i],maxi);
       }
       
       long long low=maxi;
       long long high=sum;
       long long res=0;
       while(low<=high)
       {
           long long  mid=low+(high-low)/2;
           
           int count=solve(arr,mid,n);
           if(count>k)
           {
               low=mid+1;
           }
           else
           {
                res=mid;
               high=mid-1;
              
           }
       }
       return res;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends