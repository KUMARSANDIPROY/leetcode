class Solution {
public:
    int jump(vector<int>& nums) {
        int l=nums.size();
        vector<int> v(l,INT_MAX);
        v[0]=0;
        for(int i=0;i<l-1;i++)
        {
            int x=nums[i];
            while(x>0)
            {
               if(i+x>l-1) 
               {   x--;
                   continue;
               }
               v[i+x]=min(v[i]+1,v[i+x]); 
                   x--;
            }
        }
        return v[l-1];
        
        
    }
};