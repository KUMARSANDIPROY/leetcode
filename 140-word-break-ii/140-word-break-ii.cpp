class Solution {
public:
    void h(int i,string s,unordered_set<string>&st, vector<string>&d,vector<string>&a,string tt)
    {
        if(i==s.size())
        {
            string t;
            for(auto x : d)t=t+x+" ";
            t.pop_back();
            a.push_back(t);
            return ;
        }
        
        // if(dp[i]!=-1)return dp[i];
        
        string t;
        for(int j=i;j<s.size();j++)
        {
            t=t+s[j];
            if(st.find(t)!=st.end())
            {
                d.push_back(t);
                h(j+1,s,st,d,a,t);
                d.pop_back();
            }
        }
        
    }
    vector<string>wordBreak(string s, vector<string>& wordDict) 
    {
        ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
        int n=s.size();
        unordered_set<string>st;
        for(auto a:wordDict)st.insert(a);
        vector<string>a;
        
        vector<string>d;
        h(0,s,st,d,a,"");
        
        return a;
    }
//     vector<string> wordBreak(string s, vector<string>& wordDict) 
//     {
        
//     }
};