class Solution {
public:
    vector<vector<int>> res;
    void solve(vector<int> nums,vector<int> op,int ind)
    {
       if(ind==nums.size())
       {
           res.push_back(op);
           return;
       }
    
        for(int i=ind;i<nums.size();i++)
        {
            vector<int> temp=nums;
            swap(nums[i],nums[ind]);
            solve(nums,temp,ind+1);
              
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<int> op;
        solve(nums,op,0);
        return res;
        
    }
};