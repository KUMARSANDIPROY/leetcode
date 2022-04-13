class Solution {
public:
    void solve(vector<int> candidates, int target,vector<int>op)
    {
         //cout<<candidates[0]<<"jsndc  ";
   //   if(target<0) return;
      if(target==0)
      {
          res.push_back(op);
         // cout<<"YYY   ";
          return;
      }
        if(candidates.size()==0) return;
        
        int temp=candidates[0];
        vector<int> op1,op2;
       
        op1=op;
        op2=op;
        if(temp<=target)
        {
            op1.push_back(temp);
            solve(candidates,target-temp,op1);
        }
            
        candidates.erase(candidates.begin(),candidates.begin()+1);
        solve(candidates,target,op2);
        
    }
    
    
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> op;
       
        solve(candidates,target,op);
        return res;
        
        
    }
};