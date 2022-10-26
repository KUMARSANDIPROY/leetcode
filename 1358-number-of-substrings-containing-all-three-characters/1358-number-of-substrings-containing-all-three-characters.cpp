class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int idx[3]={-1,-1,-1};
        int res=0;
        
        for(int i=0;i<s.length();i++)
        {
            idx[s[i]-'a']=i;
            
            res+=1+min({idx[0],idx[1],idx[2]});
        }
        return res;
        
        
    }
};