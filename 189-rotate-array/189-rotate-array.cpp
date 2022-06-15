class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n=nums.size();
        while(n<=k)
            k=k-n; 
        if(n>1)
        {    
            int i=0,j=n-k-1;
            while(i<j)
            {
                swap(nums[i++],nums[j--]);
            }
            i=n-k,j=n-1;
            while(i<j)
            {
                swap(nums[i++],nums[j--]);

            }
            i=0,j=n-1;
            while(i<j)
            {
                swap(nums[i++],nums[j--]);
            }
        }
    }
};