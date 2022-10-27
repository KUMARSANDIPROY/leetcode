int count;
void solve(int nums[],int n)
{
    if(n==0)
    {
        count+=1;
        return;
    }
    
    for(int idx=n;idx>0;idx--)
    {
        int temp=nums[idx];
        nums[idx]=nums[n];
        nums[n]=temp;
        if(((n)%nums[n]==0) || (nums[n]%(n)==0))
            solve(nums,n-1);
        temp=nums[idx];
        nums[idx]=nums[n];
        nums[n]=temp;
    }
    
    
}

int countArrangement(int n){

    int nums[n+1];
    for(int i=0;i<=n;i++)
        nums[i]=i;
    count=0;
    solve(nums,n);
    return count;
}