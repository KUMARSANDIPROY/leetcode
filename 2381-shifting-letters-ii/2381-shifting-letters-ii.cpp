class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        
        int n=s.size();
        vector<long long> v(n+1,0);
        
        
        for(auto it: shifts)
        {
            if(it[2]==1)
            {
                v[it[0]]++;
                v[it[1]+1]--;
            }
            else
            {
               v[it[0]]--;
                v[it[1]+1]++;
            }
                
        }
        string res="";
        int pref=0;
        for(int i=0;i<n;i++)
        {
            pref+=v[i];
            while(pref<0)
              pref+=26;
            
            int diff=(s[i]-'a'+pref)%26;
           // char ch='a'+diff;
            //res.push_back(ch);
            res+=(char)('a'+diff);
        }
        return res;
    }
};