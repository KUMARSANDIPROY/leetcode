class Solution {
public:
   
    int mod=1e9+7;
    unordered_map<int,vector<int>> mp;
    vector<int> v={0,1,2,3,4};
     vector<vector<int>> dp;
    int solve(int i,int n,int ch)
    {
        if(i==n)  
        {
            
            return 1;
        }
       
        if(dp[ch][i]!=-1)  return dp[ch][i];
        int res=0;
        for(int c:mp[ch])
            res=(res+solve(i+1,n,c))%mod;
        return dp[ch][i]=res;
    }
    
    
    int countVowelPermutation(int n) {
        
        
        mp[0]={1};
        mp[1]={0,2};
        mp[2]={0,1,3,4};
        mp[3]={2,4};
        mp[4]={0};
       
       
       
        dp.resize(5,vector<int>(n,-1));
        int ans=0;
        for(int ch=0;ch<5;ch++)
           ans=(ans+solve(1,n,ch))%mod;
        return ans;
  
    }
    
};