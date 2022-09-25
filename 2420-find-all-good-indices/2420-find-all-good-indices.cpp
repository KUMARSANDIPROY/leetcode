class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        
        vector<int> v;
        int n=nums.size();
        vector<int> left(n,1);
        vector<int> right(n,1);
        
        for(int i=1;i<n-k;i++)
        {
             if(nums[i]<=nums[i-1])
                 left[i]=1+left[i-1];
            
        }
        
        for(int i=n-2;i>=k;i--)
        {
           if(nums[i]<=nums[i+1])
               right[i]=1+right[i+1];
          
        }
         for(int i=k;i<n-k;i++)
        {
             if(left[i-1]>=k && right[i+1]>=k)
                 v.push_back(i);
             
        }
        return v;
        
    }
};