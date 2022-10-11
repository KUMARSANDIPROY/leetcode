class NumArray {
public:
      int N;
      vector<int> bits;
     vector<int> temp;
    NumArray(vector<int>& nums) {
        
         N=nums.size();
         bits.resize(nums.size()+1);
         temp=nums;
        
        for(int i=0;i<N;i++)
        {
            updateUtill(i+1,temp[i]);
        }
       
    }
    void updateUtill(int index,int val)
    {
       // val=val-temp[index];
        for(int i=index ;i<=N;i+=(i&-i))
        {
            bits[i]+=val;
            //cout<<i<<": "<<val<<endl;
        }
    }
    void update(int index, int val) {
        
        int diff=val-temp[index];
        temp[index]=val;
        updateUtill(index+1,diff);
        
    }
    int sum(int n)
    {
        int res=0;
        for(int i=n;i>0;i-=(i&-i))
        {
            res+=bits[i];
        }
        return res;
    }
    
    int sumRange(int left, int right) {
       
        return sum(right+1)-sum(left);
       
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */