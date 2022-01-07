class Solution {
public:
    int nextGreaterElement(int n) {
        int l=0,temp=n;
        
        while(temp>0)
        {
            l++;
            temp/=10;
           
        }
     
        char s[l+1];
      //  cout<<n<<" "<<l;
        sprintf(s,"%d",n);
        //cout<<"jhsdc"<<" ";
        int i;
        
        for( i=l-1;i>0;i--)
        {
            
            if(s[i]>s[i-1])
                break;
        }
        if(i==0 ) return -1;
        else
        {
            int x=i-1,index=l-1;
            int min=INT_MAX;
          
            for(int j=l-1;j>x;j--)
            {
              
                if(min>s[j] && s[j]>s[x])
                {
                   
                    min=s[j];
                    index=j;
                }
                    
             }
          
            swap(s[x],s[index]);
           
           //cout<<x<<index;             
           int p=i,q=l-1;
            while(p<q)
                swap(s[p++],s[q--]);
        }
        long res;
        sscanf(s, "%ld", &res);
        if(res>INT_MAX) return -1;
        else return res;
        
    }
};