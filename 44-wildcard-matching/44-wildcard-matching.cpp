class Solution {
public:
    bool solve(string &s,string &p,int i,int j,vector<vector<char>> &dp)
    {
        if(i==s.length() && j==p.length())
            return true;
        if(j==p.length())
            return false;
        if(i==s.length())
        {
            while(j<p.length())
            {
                if(p[j++]!='*')
                    return false;
            }
            return true;
        }
        if(dp[i][j]!=-1)  return dp[i][j];
        if(p[j]=='*')
        {
            return dp[i][j]= solve(s,p,i+1,j,dp) || solve(s,p,i,j+1,dp);
          }  
        if(p[j]=='?' || p[j]==s[i])
            return dp[i][j]=solve(s,p,i+1,j+1,dp);
        else
            return dp[i][j]=false;
        
    }
    
    bool isMatch(string s, string p) {
        
        vector<vector<char>> dp(s.length(),vector<char>(p.length(),-1));
        return solve(s,p,0,0,dp);
    }
};