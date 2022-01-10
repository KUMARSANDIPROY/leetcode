class Solution {
public:
    void merge(vector<int> &nums,int i,int j)
    {
        int mid=i+(j-i)/2;
        int l1=mid-i+1;
        int l2=j-mid;
        int *first=new int[l1];
        int *second=new int[l2];
        
        int index=i;
        
        for(int p=0;p<l1;p++)
            first[p]=nums[index++];
        for(int p=0;p<l2;p++)
            second[p]=nums[index++];
        int p=0,q=0;
        index=i;
        while(p<l1 && q<l2)
        {
            if(first[p]<second[q])
            {
                nums[index++]=first[p++];
                
            }
            else
                nums[index++]=second[q++];
        }
        while(p!=l1)
            nums[index++]=first[p++];
        while(q!=l2)
            nums[index++]=second[q++];
        
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