class Solution {
public:
    int count=0;
      void fun(vector<int>&nums,int index)
    {
        if(index==nums.size())
        {
            count+=1;
            return;
        }
        
        
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[index],nums[i]);
            if((nums[index]%(index+1)==0)||((index+1)%nums[index]==0))
             fun(nums,index+1);
            swap(nums[index],nums[i]);
        }
        
       
    }
   int countArrangement(int n) {
        vector<int>nums;
        for(int i=1;i<=n;i++)
            nums.push_back(i);
        count=0;
        fun(nums,0);
        return count;
    }
  
};