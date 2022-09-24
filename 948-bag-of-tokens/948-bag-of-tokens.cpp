class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        sort(tokens.begin(),tokens.end());
        
        int  score=0;
        int maxi=0;
        if(tokens.size()==0)  return 0;
        int i=0;
        int j=tokens.size()-1;
        if(power<tokens[0] ) return 0;
        
        while(i<=j)
        {
           if(score>0)
           {
              if(power>=tokens[i])
              {
                  score++;
                  maxi=max(score,maxi);
                  power=power-tokens[i];
                  i++;
              }
              else
              {
                  power+=tokens[j--];
                  score--;
              }
           }
            else if(score==0)
            {
                if(power<tokens[i])
                break;
                else
                {
                     power-=tokens[i++];
                     score++;
                    maxi=max(score,maxi);
                }
            }
        }
        return maxi;
    }
};