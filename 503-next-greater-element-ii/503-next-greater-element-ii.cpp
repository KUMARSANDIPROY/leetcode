class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        stack<int> s;
        int n=nums.size();
        vector<int> v;
        for(int i=n-2;i>=0;i--)
        {
            while(s.size()!=0 && s.top()<nums[i])
                s.pop();
            s.push(nums[i]);
        }
        
        for(int i=n-1;i>=0;i--)
        {
            while(s.size()>0 && s.top()<=nums[i])
            {
                s.pop();
            }
            //cout<<s.top()<<nums[i]<<" ";
            if(s.size()==0)
                v.push_back(-1);
            else
                v.push_back(s.top());
            
            s.push(nums[i]);
        }
        reverse(v.begin(),v.end());
        return v;
        
    }
};