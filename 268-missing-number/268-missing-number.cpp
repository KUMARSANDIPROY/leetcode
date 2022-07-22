class Solution {
public:
    int missingNumber(vector<int>& array) {
        int i=0;
        int n=array.size();
        while(i<n)
        {
            if(array[i]==i || array[i]==n)
                i++;
            else if(array[i]!=array[array[i]])
                  swap(array[i],array[array[i]]);
                    
                
            
        }
        for(int i=0;i<n;i++)
        {
            if(array[i]!=i)
               return i;
        }
        return n;
    }
};