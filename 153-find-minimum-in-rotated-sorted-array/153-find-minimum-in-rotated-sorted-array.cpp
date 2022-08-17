class Solution {
public:
    int findMin(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        int l=j+1,mid,prev,next;
        
        while(i<=j)
        {
            mid=i+(j-i)/2;
           
            prev=(mid-1+l)%l;
            next=(mid+1)%l;
            // cout<<mid<<prev<<next<<" ";
            
            if(nums[prev]>nums[mid] && nums[mid]<nums[next])
                break;
//           
              else if(nums[mid]<=nums[j])
                  j=mid-1;
            
              else if(nums[mid]>=nums[i])
                  i=mid+1;
            
            
        }
       return nums[mid];
    }
};