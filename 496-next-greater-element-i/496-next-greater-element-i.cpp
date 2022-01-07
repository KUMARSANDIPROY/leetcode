class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        stack<int> s;
        map<int,int> mp;
        
        for(int i:nums2)
        {
            while(s.empty()==false && s.top()<i)
            {
                mp[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        for(int i:nums1)
        {
            if(mp.count(i))
                v.push_back(mp[i]);
            else
                v.push_back(-1);
        }
        
        return v;
        
        
    } 
    
};