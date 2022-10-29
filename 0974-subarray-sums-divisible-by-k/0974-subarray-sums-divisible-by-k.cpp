class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int count=0;
        map<int,int> mp;
        int prev=0;
        mp[0]=1;
         
        for(int i=0;i<nums.size();i++)
        {
            prev+=nums[i];
            int rem=prev%k;
            if(rem<0) rem=rem+k;
            if(mp[rem]>0)
                count+=mp[rem];
            mp[rem]++;
        }
        
        return count;
        
    }
};