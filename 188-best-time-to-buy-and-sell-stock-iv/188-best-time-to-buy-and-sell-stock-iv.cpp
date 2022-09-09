class Solution {
public:
    int maxProfit(int B, vector<int>& A) {
        
            int n=A.size();
            int total=B*2;
            vector<vector<int>> dp(n+1,vector<int>(total+1,0));



            for(int idx=n-1;idx>=0;idx--)
            {

                for(int tran=total-1;tran>=0;tran--)
                {
                    if(tran%2==0)
                       dp[idx][tran]=max(-A[idx]+dp[idx+1][tran+1] ,  dp[idx+1][tran]);
                    else
                        dp[idx][tran]=max(A[idx]+dp[idx+1][tran+1] ,  dp[idx+1][tran]);  
                }
            }
            return dp[0][0];

    }
};