class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r)
    {
        vector<bool>a(l.size(),1);
        for(int i=0;i<l.size();i++)
        {
            int s=l[i],e=r[i];
            vector<int>n;
            for(int j=s;j<=e;j++)
            {
                n.push_back(nums[j]);
            }
            sort(n.begin(),n.end());
            int d=n[1]-n[0];
            for(int k=1;k<n.size();k++)
            {
                if(k+1<n.size() && d!=(n[k+1]-n[k]))
                {
                  a[i]=0;  
                    break;
                }
            }
            
        }
        
        
        return a;
        
    }
};