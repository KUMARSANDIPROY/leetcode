class Solution {
public:
    
    map<string,int> mp;
    int find_min(string s)
    {
        stack<char> st;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
                st.push(s[i]);
            
            if(s[i]==')')
            {
                if(st.empty())
                    st.push(s[i]);
                else if(st.top()==')')
                    st.push(s[i]);
                else if(st.top()=='(')
                    st.pop();
            }
        }
        return st.size();
    }
    void solve(int ml,string str,vector<string> &res)
    {
       if(mp[str]!=0) return;
        else
            mp[str]++;
        if(ml==0)
        {
            int x=find_min(str);
            if(x==0)
            {
               // if(find(res.begin(),res.end(),str)==res.end())
                    res.push_back(str);
                
            }
            return;
        }
        
        for(int i=0;i<str.length();i++)
        {
        
            string s1=str.substr(0,i);
            string s2=str.substr(i+1);
            s1=s1+s2;
          
                
            solve(ml-1,s1,res);
        }
        
    }
    
    vector<string> removeInvalidParentheses(string s) {
        
        int ml=find_min(s);
        //cout<<ml;
        vector<string> res;
        string str="";
        solve(ml,s,res);
        return res;
    }
};