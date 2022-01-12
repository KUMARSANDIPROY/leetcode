class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int a,b,maxp=0,temp;
        int min=INT_MAX;
        int l=prices.size();
        for(int i=0;i<l;i++)
        {
          
         if(min>prices[i])
              min=prices[i];
         temp=prices[i]-min;
         if(maxp<temp)
             maxp=temp;
         }
        return maxp;
    }
};