class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int l=nums.size();
        vector<int> v;
        v=nums;
        int temp=nums[l-1],index1=-1;
        for(int i=l-2;i>=0;i--)
        {
            if(temp>nums[i])
            {
                index1=i;
                break;
             }
            else
                temp=nums[i];
        }
        if(index1==-1)
            reverse(nums.begin(),nums.end());
        else
        {
            for(int i=l-1;i>index1;i--)
            {

                if(nums[i]>nums[index1])
                {
                    swap(nums[index1],nums[i]);
                    break;
                 }
            }
            reverse(nums.begin()+index1+1,nums.end());
        }
    } 
       
};