class Solution {
public:
//     int N=100001;
//     int mod=1e9+7;
//     map<char,int> ind;
//     int solve(int i,int n,int &ans,char ch,unordered_map<char,vector<char>> mp,vector<vector<int>> &dp)
//     {
//         if(i==n)  
//         {
            
//             return 1;
//         }
//         int k=ind[ch];
//         if(dp[k][i]!=-1)  return dp[k][i];
//         int res=0;
//         for(char c:mp[ch])
//             res=(res+solve(i+1,n,ans,c,mp,dp))%mod;
//         return dp[k][i]=res;
//     }
    
    
    int countVowelPermutation(int n) {
        
//         unordered_map<char,vector<char>> mp;
//         vector<char> v={'a','e','i','o','u'};
//         mp['a'].push_back('e');
//         mp['e']={'a','i'};
//         mp['i']={'a','e','o','u'};
//         mp['o']={'i','u'};
//         mp['u']={'a'};
       
//         ind['a']=0;
//          ind['e']=1;
//          ind['i']=2;
//          ind['o']=3;
//          ind['u']=4;
//         vector<vector<int>> dp(5,vector<int>(n,-1));
//         //memset(dp,-1,sizeof(dp));
//         int ans=0;
//         for(char ch:v)
//            ans=(ans+solve(1,n,ans,ch,mp,dp))%mod;
//         return ans;
        long a = 1, e = 1, i = 1, o = 1, u = 1, mod = pow(10, 9)+7;
        long a2, e2, i2, o2, u2; 
        
        for (int j = 2; j <= n; j++) {
            a2 = (e + i + u) % mod;
            e2 = (a + i) % mod;
            i2 = (e + o) % mod;
            o2 = i;
            u2 = (o + i) % mod;
            
            a = a2, e = e2, i = i2, o = o2, u = u2;
        }
        return (a + e + i + o + u) % mod;
    }
    
};