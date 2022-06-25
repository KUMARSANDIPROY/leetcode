class Solution {
public:
    string reorganizeString(string s) {
        
        map<char,int> mp;
        int l=s.size();
        string res(l,'0');
      
        
        int mx=INT_MIN;
        char mxchr;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
            if(mx<mp[s[i]])
            {
                mx=mp[s[i]];
                mxchr=s[i];
            }
        }
        
        int idx=0;
        if(mx>(l+1)/2) return "";
        
        while(mp[mxchr]>0)
        {
            res[idx]=mxchr;
            idx=idx+2;
            mp[mxchr]--;
            mx--;
        }
        
        for(int i=0;i<26;i++)
        {
          while(mp['a'+i]>0)
          {
              if(idx>=l)
                  idx=1;
              res[idx]='a'+i;
              mp['a'+i]--;
              char c='a'+i;
              idx+=2;
             // cout<<c<<idx<<"   ";
          }
            
        }
        return res;
        
    }
};