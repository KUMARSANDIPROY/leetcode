class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<int> hash(nums.size());
        int maxi=0;
        int max_index=0;
        vector<int> dp(nums.size(),1);
        for(int i=0;i<nums.size();i++)
        {
            hash[i]=i;
            for(int prev=0;prev<i;prev++)
            {
                 
                if(nums[i]%nums[prev]==0 && 1+dp[prev]>dp[i])
                {
                   
                   hash[i]=prev;
                   dp[i]=1+dp[prev];
                    // cout<<nums[prev]<<nums[i]<<hash[i]<<dp[i]<<" ";
                }
            }
            if(maxi<dp[i])
            {
                maxi=dp[i];
                max_index=i;
                //cout<<maxi;
            }
        }
        
        vector<int> temp;
        temp.push_back(nums[max_index]);
        int idx=max_index;
       //cout<<hash[3]<<"  ";
        while(hash[idx]!=idx)
        {
           idx=hash[idx];
            temp.push_back(nums[idx]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};