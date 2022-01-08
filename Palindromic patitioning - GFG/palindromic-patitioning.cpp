// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

   int t[501][501];
   //memset(t,-1,sizeof(t));
   
    bool ispallindrome(string str,int i, int j)
    {
        while(i<j)
        {
            if(str[i++]!=str[j--])
               return false;
        }
        return true;
    }

    int solve(string str,int i,int j)
    {
        if(i>=j)
           return 0;
        if(ispallindrome(str,i,j)) return 0;   
           
        int ans=INT_MAX,left,right;   
        if(t[i][j]!=-1)
           return t[i][j];
        for(int k=i;k<j;k++)
        {
            //int temp=solve(str,i,k)+solve(str,k+1,j)+1;
            if(t[i][k]!=-1)
                left=t[i][k];
            else left=solve(str,i,k);
            
            if(t[k+1][j]!=-1)
               right=t[k+1][j];
            else 
               right=solve(str,k+1,j);
               
            int temp=left+right+1;   
            
            ans=min(temp,ans);
        }
        return t[i][j]=ans;
    }


    int palindromicPartition(string str)
    {
       int i=0,j=str.length()-1;
       for(int i=0;i<501;i++)
      {
           for(int j=0;j<501;j++)
              t[i][j]=-1;
      }
       
       return solve(str,i,j);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends