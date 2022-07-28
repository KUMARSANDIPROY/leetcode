class Solution {
public:
    int solve(vector<int> &arr,int ind,int k,vector<int> &dp)
    {
        int n=arr.size();
        if(ind==n)  return 0;
        if(dp[ind]!=-1) return dp[ind];
        int maxi=INT_MIN;
        int max_ans=INT_MIN;
        
        int len=0;
        for(int i=ind;i<min(ind+k,n);i++)
        {
            len++;
            maxi=max(maxi,arr[i]);
            int sum=maxi * len + solve(arr,i+1,k,dp);
            max_ans=max(max_ans,sum);
        }
        
        return dp[ind]=max_ans;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int n=arr.size();
        vector<int> dp(n+1,0);
        //return solve(arr,0,k,dp);
        
        for(int ind=n-1;ind>=0;ind--)
        {
            int maxi=INT_MIN;
            int max_ans=INT_MIN;

            int len=0;
            for(int i=ind;i<min(ind+k,n);i++)
            {
                len++;
                maxi=max(maxi,arr[i]);
                int sum=maxi * len + dp[i+1];
                max_ans=max(max_ans,sum);
            }

            dp[ind]=max_ans;
        }
        return dp[0];
    }
};