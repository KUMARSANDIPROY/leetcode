//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	vector<int> DistinctSum(vector<int>nums){
	    // Code here
	    
	    int sum=0;
	    
	    int n=nums.size();
	    
	    for(int i=0;i<n;i++)
	       sum+=nums[i];
	   
	   vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));    
	   
	   for(int i=0;i<=n;i++)
	   {
	       for(int j=0;j<=sum;j++)
	       {
	           if(i==0)  
	              dp[i][j]=false;
	           if(j==0)
	              dp[i][j]=true;
	       }
	   }
	   
	   for(int i=1;i<=n;i++)
	   {
	       for(int j=1;j<=sum;j++)
	       {
	           if(j>=nums[i-1])
	             dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i-1]];
	           
	           else
	             dp[i][j]=dp[i-1][j];
	       }
	   }
	   
	   vector<int> res;
	   for(int i=0;i<=sum;i++)
	   {
	       if(dp[n][i])
	          res.push_back(i);
	   }
	   
	   return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int> ans = obj.DistinctSum(nums);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}

// } Driver Code Ends