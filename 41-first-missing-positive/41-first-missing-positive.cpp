class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        
        int n=arr.size();
         for(int i=0;i<n;i++)
        {
            if(arr[i]>0 && arr[i]<=n)
            {
                int pos=arr[i]-1;
                if(arr[pos]!=pos+1)
                {
                    swap(arr[pos],arr[i]);
                    i--;
                }
            }
            else if(arr[i]<=0 && arr[i]>n)
               continue;
        }
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=i+1)
               return i+1;
        }
        return n+1;
    }
};