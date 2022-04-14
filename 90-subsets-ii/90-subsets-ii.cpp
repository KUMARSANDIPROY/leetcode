class Solution {
public:
    void solve(vector<int> nums,vector<int> op,int ind)
    {
        if(ind==nums.size())
        {
            if(find(res.begin(),res.end(),op)==res.end())
            {
               // sort(op.begin(),op.end());
                res.push_back(op);
            }
            return;
         }
        
       // vectro<int> op1,op2;
        solve(nums,op,ind+1);
        op.push_back(nums[ind]);
        solve(nums,op,ind+1);
        
        
    }
    
    
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       
        sort(nums.begin(),nums.end());
        vector<int> op;
        solve(nums,op,0);
        return res;
        
    }
};