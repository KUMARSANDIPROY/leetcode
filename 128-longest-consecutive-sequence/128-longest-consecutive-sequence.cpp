class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> s(nums.begin(),nums.end());
        
        int maxi=0;
        int count=0;
        
        for(int i:s)
        {
           if(s.find(i-1)==s.end())
           {
               count=1;
               int x=i;
               while(s.find(x+1)!=s.end())
               {
                   count++;
                   x=x+1;
                   
               }
               maxi=max(count,maxi);
           }
        }
        return maxi;
    }
};