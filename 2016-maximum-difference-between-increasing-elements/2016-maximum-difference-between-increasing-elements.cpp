class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        
        int l=nums.size();
        int mx=nums[l-1],mn=nums[0];
        int res=-1;
        
        for(int i=0;i<l;i++)
        {

            for(int j=i+1;j<l;j++)
            {
                if(nums[i]<nums[j])
                    res=max(nums[j]-nums[i],res);
            }
        }
        return res;
        
    }
};