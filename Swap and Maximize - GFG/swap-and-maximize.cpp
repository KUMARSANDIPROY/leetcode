// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;++i)
			cin>>arr[i];
		cout<<maxSum(arr,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


long long int maxSum(int arr[], int n)
{
    sort(arr,arr+n);
    long long int sum=0;
    for(int i=0;i<n/2;i++)
    {
        sum=sum+abs(arr[i]-arr[n-i-1])+abs(arr[i+1]-arr[n-i-1]);
       // cout<<arr[i]<<arr[n-i-1]<<arr[i+1]<<sum<<" ";
    }
    sum+=abs(arr[n/2]-arr[0]);
    return sum;
    
}