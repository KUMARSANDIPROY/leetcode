class Solution {
public:
    int solve(string s,int i,vector<int> &dp)
    {
        if(i==s.length())  return 1;
        int one=0,two=0;
        if(dp[i]!=-1)  return dp[i];
        if(s[i]!='0')
        {
            one=solve(s,i+1,dp);
            if(i+1<s.length() && (s[i]=='1' || (s[i]=='2' && (s[i+1]-'0')<=6)))
                two=solve(s,i+2,dp);
             return dp[i]=one +two;  
        }
        else //if(s[i]=='0')
               return dp[i]=0;
    }
    
    int numDecodings(string s) {
        
        int n=s.length();
        vector<int> dp(s.length(),-1);
       // dp[n-1]=1;
        return solve(s,0,dp);
    }
};