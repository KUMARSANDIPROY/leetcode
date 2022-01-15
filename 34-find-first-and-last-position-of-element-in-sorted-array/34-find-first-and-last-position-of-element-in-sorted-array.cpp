class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> v(2,-1);
        int n=nums.size();
        int l=0,r=n-1,mid;
         while(l<=r)
        {
             mid=(l+r)/2;
             //cout<<l<<r<<mid<<endl;
             if(nums[mid]==target)
               {  
                  // cout<<"Found";
                   break;
               }
               if(nums[mid]>target)
               {
                   r=mid-1;
               }
               else if(nums[mid]<target)
               {
                   l=mid+1;
               }
            }
        if(l>r) return v;
        else
        {
            
            int i=mid,j=mid;
            if(mid!=0)
            {
                while(nums[i-1]==target)
                {
                    i--;
                    if(i==0) break;
                }
            } 
            if(mid!=n-1)
            {
                while(nums[j+1]==target)
                {
                    j++;
                    if(j==n-1) break;
                }
            }   
            v[0]=i;
            v[1]=j;
            
                return v;
        }
        
    }
};