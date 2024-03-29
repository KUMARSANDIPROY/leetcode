class Solution {
public:
    int countSubstrings(string s) {
        
        int n=s.length();
       
        //int dp[n+1][n+1];
        vector<vector<int>> dp(n,vector<int>(n,0));
        int count=0;
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
            count++;
        }
        
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                count++;
                dp[i][i+1]=1;
            }
        }
        
        for(int k=3;k<=n;k++)
        {
           for(int i=0;i<n-k+1;i++)
           {
               int j=i+k-1;
               if(s[i]==s[j] && dp[i+1][j-1]==1)
               {
                   dp[i][j]=1;
                   count++;
               }
           }
        }
        return count;
        
    }
};