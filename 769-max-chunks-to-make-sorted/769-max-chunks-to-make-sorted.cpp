class Solution {
public:
    int maxChunksToSorted(vector<int>& a) 
    {
        int n=a.size();
        vector<int>mi(n),ma(n);
        ma[0]=a[0];
        mi[n-1]=a[n-1];
        for(int i=1;i<n;i++)
        {
             ma[i]=max(ma[i-1],a[i]);
        }
        for(int i=n-2;i>=0;i--)
        {
            mi[i]=min(mi[i+1],a[i]);
        }
        
        int count=0;
        
        for(int i=0;i<n-1;i++)
        {
            if(ma[i]<=mi[i+1])
                   count++;
        }
        
        return count+1;
        
        
    }
};