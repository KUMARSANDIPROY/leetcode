class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
     
        int max_straight_sum=INT_MIN;
        int temp_max_sum=0;
        int array_sum=0;
        int min_straight_sum=0;
        int temp_min_sum=0;
        
        for(int i=0;i<nums.size();i++)
        {
            array_sum+=nums[i];
            temp_max_sum+=nums[i];
            max_straight_sum=max(max_straight_sum,temp_max_sum);
            if(temp_max_sum<0)
                temp_max_sum=0;
            
            temp_min_sum+=nums[i];
            min_straight_sum=min(min_straight_sum,temp_min_sum);
            if(temp_min_sum>0)
                temp_min_sum=0;
        }
        
        if(array_sum==min_straight_sum)  //all elements are negative
            return max_straight_sum;
        else
            return max(max_straight_sum,array_sum-min_straight_sum);
    }
};