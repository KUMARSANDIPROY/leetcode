class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        if(nums.size()==1) return 0;
        int mid;
        while(i<=j)
        {
            //cout<<"kjshdc";
            mid=i+(j-i)/2;
            if(mid==0)
            {
                if(nums[mid+1]<nums[mid]) break;
                else i=mid+1;
            }
            else if(mid==nums.size()-1)
            {
                if(nums[mid-1]<nums[mid]) break;
                else j=mid-1;
            }
            else if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1])
               break;
            else 
            {
                if(nums[mid-1]>nums[mid])
                    j=mid-1;
                else if(nums[mid+1]>nums[mid])
                    i=mid+1;
            }  
            
        }
        return mid;
    }
};