class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        
        int left=0;
        
        int count_T=0,count_F=0;
        int ans=0;
        for(int right=0;right<answerKey.size();right++)
        {
            if(answerKey[right]=='T')
                count_T++;
            else
                count_F++;
            
            while(count_F > k && count_T>k)
            {
                if(answerKey[left]=='T')
                    count_T--;
                else
                    count_F--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
             return ans;
    }
};