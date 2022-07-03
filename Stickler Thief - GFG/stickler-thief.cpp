// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
   
    int solve(int arr[],int n,vector<int> &dp)
    {
        if(dp[n]!=-1) return dp[n];
        if(n<=0)
        {
            return 0;
            
        }
        int sum1=arr[n-1]+solve(arr,n-2,dp);
        int sum2=solve(arr,n-1,dp);
        
        return dp[n]=max(sum1,sum2);
        
        
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int N=1e4+1;
        vector<int> dp(N,-1);
        return solve(arr,n,dp);
      
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends