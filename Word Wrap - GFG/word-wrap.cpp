// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
     int dp[501][2001];
    
    int solve(vector<int> &nums,int rem,int i,int k)
    {
        if(i==nums.size())  return 0;
        
        if(dp[i][rem]!=-1)  return dp[i][rem];
        
         int ans;
        if(nums[i]>rem)
           ans=(rem+1)*(rem+1) + solve(nums,k-nums[i]-1,i+1,k);
           
        else
        {
            int same_line=solve(nums,rem-nums[i]-1,i+1,k);
            int diff_line=(rem+1)*(rem+1) + solve(nums,k-nums[i]-1,i+1,k);
            ans=min(same_line,diff_line);
        }
        return dp[i][rem]=ans;
    }
    
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        memset(dp,-1,sizeof(dp));
        int rem=k;
        return solve(nums,k,0, k);
    } 
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends