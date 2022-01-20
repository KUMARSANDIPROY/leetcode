class Solution {
public:
    int findMin(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        int l=j+1,mid,prev,next;
        
        while(i<=j)
        {
            mid=(i+j)/2;
           
            prev=(mid-1+l)%l;
            next=(mid+1)%l;
            // cout<<mid<<prev<<next<<" ";
            
            if(nums[prev]>=nums[mid] && nums[mid]<=nums[next])
                break;
            else if(nums[0]<=nums[mid] && nums[mid]<=nums[l-1])
                j=mid-1;
            
            else if(nums[0]>nums[mid])
                j=mid-1;
            else if(nums[l-1]<nums[mid])
                i=mid+1;
           
            
        }
       return nums[mid];
    }
};