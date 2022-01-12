class Solution {
public:
    void merge(vector<int> &nums,int i,int j)
    {
        int mid=i+(j-i)/2;
        int l1=mid-i+1;
        int l2=j-mid;
        int left[l1],right[l2];
        int index=i;
        for(int k=0;k<l1;k++)
            left[k]=nums[index++];
        for(int k=0;k<l2;k++)
            right[k]=nums[index++];
        int p1=0,q1=0,k1=i;
         //cout<<"mbc";
        while(p1<l1 && q1<l2)
        {
            if(left[p1]<right[q1])
                nums[k1++]=left[p1++];
            else
                nums[k1++]=right[q1++];
        }
      // 
        while(p1!=l1)
            nums[k1++]=left[p1++];
        while(q1!=l2)
            nums[k1++]=right[q1++];
        
    }
               
    
    void solve(vector<int> &nums,int i,int j)
    {
        if(i>=j)
            return;
        int mid=i+(j-i)/2;
        solve(nums,i,mid);
        solve(nums,mid+1,j);
        
        merge(nums,i,j);
        
     }
    
    
    vector<int> sortArray(vector<int>& nums) {
        int size=nums.size();
        solve(nums,0,size-1);
        return nums;
    }
};