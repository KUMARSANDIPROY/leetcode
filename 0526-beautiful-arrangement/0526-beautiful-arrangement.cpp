class Solution {
public:
    int count=0;
      void fun(vector<int>&nums,int index)
    {
        if(index==0)
        {
            count+=1;
            return;
        }
        
        
        for(int i=index;i>0;i--)
        {
            swap(nums[index],nums[i]);
            if((nums[index]%(index)==0)||((index)%nums[index]==0))
             fun(nums,index-1);
            swap(nums[index],nums[i]);
        }
        
       
    }
   int countArrangement(int n) {
        vector<int>nums;
        for(int i=0;i<=n;i++)
            nums.push_back(i);
        count=0;
        fun(nums,n);
        return count;
    }
  
};