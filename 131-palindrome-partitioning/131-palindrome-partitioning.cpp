class Solution {
public:
    bool is_palindrome(string st)
    {
       int i=0;
        int j=st.length()-1;
        while(i<j)
        {
           if(st[i]!=st[j])
            return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(string s,vector<string> temp,vector<vector<string>> &ans)
    {
      if(s.size()==0)
      {
          ans.push_back(temp);
          return;
      }  
          for(int i=0;i<s.length();i++)
          {
              string sub=s.substr(0,i+1);
              if(is_palindrome(sub))
              {
                  temp.push_back(sub);
                  int l=s.length()-i-1;
                  string remain=s.substr(i+1,l);
                  solve(remain,temp,ans);
                  temp.pop_back();
              }
          }
      }

    
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        vector<string> temp;
        
        solve(s,temp,ans);
        return ans;
    }
};