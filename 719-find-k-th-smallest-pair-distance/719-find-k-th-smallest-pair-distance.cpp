class Solution {
public:
    int solve(vector<int> nums,int mid)
    {
        int count=0;
        
        for(int i=0;i<nums.size();i++)
        {
            count+=upper_bound(nums.begin()+i,nums.end(),nums[i]+mid)-(nums.begin()+i+1);
        }
        return count;
    }
    
    
    int smallestDistancePair(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        int high=nums[n-1]-nums[0];
        
        int low=nums[1]-nums[0];
        
        for(int i=1;i<n-1;i++)
        {
            low=min(low,nums[i+1]-nums[i]);
        }
        
        while(low<high)
        {
            int mid=(low+ high)/2;
            
            int count=solve(nums,mid);
            if(count<k)
            {
                low=mid+1;
            }
            else high=mid;
        }
        return low;
        
    }
};