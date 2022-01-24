class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string A=s;
        int l=A.length();
        int t[l+1][l+1];
        string B=A;
        reverse(B.begin(),B.end());
        for(int i=0;i<=l;i++)
        {
            for(int j=0;j<=l;j++)
            if(j==0 || i==0)
               t[i][j]=0;
        }
        
        for(int i=1;i<=l;i++)
        {
            for(int j=1;j<=l;j++)
            {
                if(A[i-1]==B[j-1])
                {
                   t[i][j]=1+t[i-1][j-1];
                 //  cout<<A[i-1]<<" ";
                }
                else 
                   t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
        return t[l][l];
        
    }
};