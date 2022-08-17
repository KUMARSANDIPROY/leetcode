class Solution {
public:
    int BS(vector<int> nums,int start,int end,int target)
    {
        int i=start,j=end,mid;
        while(i<=j)
        {
            mid=(i+j)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]>target)
                j=mid-1;
            else
                i=mid+1;
                
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) 
    {
        int low=0,high,n=nums.size();
        high=n-1;
        int mid,prev,next;
        while(high>=low)
        {
            mid=(low+high)/2;
            prev=(mid-1+n)%n;
            next=(mid+1)%n;
                 
            if(nums[prev]>nums[mid] && nums[mid]<nums[next])
                  break;
//            else if(nums[0]<=nums[mid] && nums[mid]<=nums[n-1])//when array is sorted
//                 high=mid-1;
           else if(nums[n-1]>=nums[mid])
                high=mid-1;         
           else if(nums[0]<=nums[mid])
                low=mid+1;

           
        }
        
   
        if(target>nums[n-1])
            return BS(nums,0,mid-1,target);
        else 
            return BS(nums,mid,n-1,target);
        
      
    }
};