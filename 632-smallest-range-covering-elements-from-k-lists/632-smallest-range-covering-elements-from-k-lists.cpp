class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n=nums.size();
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> q;
        
        vector<int> ans(2);
        int diff=INT_MAX;
        int high=INT_MIN;
        for(int i=0;i<n;i++)
        { 
            q.push(make_tuple(nums[i][0],i,0));
            high=max(high,nums[i][0]);
            
        }
        
        while(true)
        {
            auto t=q.top();
            q.pop();
            int low=get<0>(t);
            int list=get<1>(t);
            int idx=get<2>(t);
            
            if(diff > high-low)
            {
                ans[0]=low;
                ans[1]=high;
                diff=high-low;
            }
            if(nums[list].size()<=idx+1) 
            {
              // cout<<list<<low<<" "<<high<<"   ";
                break;
            }
            
            high=max(high,nums[list][idx+1]);
            q.push(make_tuple(nums[list][idx+1],list,idx+1));
            
        }
        return ans;
    }
};