class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> res;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > q;
        
        map<int,int> mp;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto i=mp.begin();i!=mp.end();i++)
        {
            q.push({i->second,i->first});
            if(q.size()>k)
                q.pop();
            
        }
        while(q.empty()==false)
        {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};