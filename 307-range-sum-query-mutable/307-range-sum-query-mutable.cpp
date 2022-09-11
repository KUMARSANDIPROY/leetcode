class NumArray {
public:
    vector<int> tree;
    //int diff=0;
    int n;
    void buildTree(vector<int> &nums,int idx,int left,int right)
    {
        if(left==right)
        {
            tree[idx]=nums[left];
            return;
        }
        
        int mid=(left+right)/2;
        
        buildTree(nums,2*idx+1,left,mid);

        buildTree(nums,2*idx+2,mid+1,right);
        
        tree[idx]=tree[2*idx+1] + tree[2*idx+2];
    }
    void updateUtil(int pos,int left,int right,int index,int val)
    {
        if(index<left || index > right)  return ;
        
        if(left==right)
        {
            if(left==index)
            {
               // cout<<".kvn  ";
                tree[pos]=val;
            }
            return;
        }
        
        int mid=(left+right)/2;
        
        updateUtil(2*pos+1,left,mid,index,val);
        updateUtil(2*pos+2,mid+1,right,index,val);
        
        tree[pos]=tree[2*pos+1] + tree[2*pos+2];
       // cout<<tree[pos]<<" kjwbk  ";
        
        
    }
    
    int sumRangeUtill(int pos,int low,int high,int ql ,int qr)
    {
        if(qr<low || high<ql)  return 0;
        
        if(ql<=low && high<=qr)  return tree[pos];
        
        int mid=(low+high)/2;
        
        return sumRangeUtill(2*pos+1,low,mid,ql,qr) + sumRangeUtill(2*pos+2,mid+1,high,ql,qr);
    }
        
    NumArray(vector<int>& nums) {
        
        n=nums.size();
        tree.resize(4*n , 0);
        buildTree(nums,0,0,n-1);
        
    }
    
    void update(int index, int val) {
        
        if(n==0)  return ;
        
        updateUtil(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        
        if(n==0)  return 0;
        
        return sumRangeUtill(0,0,n-1,left,right);
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */