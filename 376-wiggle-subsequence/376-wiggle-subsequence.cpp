class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) 
    {
        if(nums.size()<=1) return nums.size(); 
       int prev_diff=nums[1]-nums[0],count;
      
       prev_diff==0 ? count=1:count=2;
       int cur_diff;
       for(int i=2;i<nums.size();i++)
       {
           cur_diff=nums[i]-nums[i-1];
           if((cur_diff<0 && prev_diff>=0) || (cur_diff>0 && prev_diff<=0))
              {
                  count++;
                  prev_diff=cur_diff;
              }
       }
       return count;
    }
};