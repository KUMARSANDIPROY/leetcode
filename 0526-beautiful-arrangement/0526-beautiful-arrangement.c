
int count=0;
      void fun(int nums[],int index)
    {
        if(index==0)
        {
            count+=1;
            return;
        }
        
        
        for(int i=index;i>0;i--)
        {
           // swap(nums[index],nums[i]);
            int temp=nums[i];
            nums[i]=nums[index];
            nums[index]=temp;
            
            if((nums[index]%(index)==0)||((index)%nums[index]==0))
             fun(nums,index-1);
             temp=nums[i];
            nums[i]=nums[index];
            nums[index]=temp;
           // swap(nums[index],nums[i]);
        }
        
       
    }
   int countArrangement(int n) {
    
        int nums[n+1];
        for(int i=0;i<=n;i++)
            nums[i]=i;
     
        count=0;
        fun(nums,n);
        return count;
    }
