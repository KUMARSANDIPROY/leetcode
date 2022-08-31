class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        
        int rem1=1e8;
        int rem2=1e8;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(nums[i]%3==1)
            {
                rem2=min(rem2,nums[i]+rem1);
                rem1=min(rem1,nums[i]);
            }
            if(nums[i]%3==2)
            {
                rem1=min(rem1,nums[i]+rem2);
                rem2=min(rem2,nums[i]);
            }
        }
        if(sum%3==1)
            return sum-rem1;
        else if(sum%3==2)  
            return sum-rem2;
        else return sum;
            
        
    }
};