class Solution {
public:
    int minSwaps(string S) {
        int mx=0;
        int count=0;
        
        for(int i=0;i<S.length();i++)
        {
            if(S[i]==']')
            {
                count++;
                mx=max(mx,count);
            }
            else
                count--;
        }
        
        return (mx+1)/2;
        
    }
};