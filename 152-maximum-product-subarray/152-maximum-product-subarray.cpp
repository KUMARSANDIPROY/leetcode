class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
       int overall_max=nums[0];
       int current_max=nums[0];
       int current_min=nums[0]; 
       for(int i=1;i<nums.size();i++)
       {
           int temp=current_max;
           current_max=max({nums[i],nums[i]*current_max,nums[i]*current_min});
           current_min=min({nums[i],nums[i]*temp,nums[i]*current_min});
           overall_max=max(overall_max,current_max);
       }
        return overall_max;
    }
};