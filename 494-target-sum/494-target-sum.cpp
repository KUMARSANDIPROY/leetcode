class Solution {
public:
    int subsetsum(vector<int> &nums,int target,int n)
    {
        int t[n+1][target+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=target;j++)
            {
                if(i==0) t[i][j]=0;
                if(j==0) t[i][j]=1;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=target;j++)
            {
                if(nums[i-1]<=j)
                    t[i][j]=t[i-1][j-nums[i-1]]+ t[i-1][j];

                else 
                    t[i][j]=t[i-1][j];     
            }
        }
        
        
        return t[n][target];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum=0;
        int n=nums.size();
        if(n==1 && abs(target)!=abs(nums[0])) return 0;
        else if(n==1 && abs(target)==abs(nums[0])) return 1;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if((sum+target)%2!=0) return 0;
       // sum=sum-(sum-target)/2;
        sum=(sum+target)/2;
        int res=subsetsum(nums,sum,n);
        return res;
        
    }
};