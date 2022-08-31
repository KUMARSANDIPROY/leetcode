class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count=0;
        int i=0;
        int j=1;
        map<string,int> mp;
        map<int,int>freq;
        for(int p=0;p<nums.size();p++)
            freq[nums[p]]++;
        
       // while(i<j && j<nums.size())
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                int diff=nums[j]-nums[i];
                if(diff==k)
                {

                   // cout<<i<<" "<<j<<endl;
                    string s=to_string(nums[i])+to_string(nums[j]);
                    if(mp.find(s)==mp.end() )//|| (freq[nums[i]]>1 && freq[nums[j]]>1))
                        count++;
                    mp[s]=1;
                    // i++;
                    // j++;
                }    
                // else if(diff<k)
                //     j++;
                // else i++;
            }
        }
        return count;
    }
};