// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
int solve(vector<pair<int,int>> v,int n,int prev,vector<int> &dp)
{
    if(n==0) 
    {
        return 0;
    }
    if(dp[n]!=-1) return dp[n];
    
    int take=0,not_take=0;
    
    if(prev==-1 || prev > v[n-1].second)
    
        take = 1+solve(v,n-1,v[n-1].first,dp);
    
    not_take=solve(v,n-1,prev,dp);
    
    return dp[n]=max(take,not_take);
    
  
}

int maxChainLen(struct val p[],int n)
{
//Your code here
   // int res=INT_MIN;
    int prev=-1;
    
    vector<pair<int,int>> v;
    
    for(int i=0;i<n;i++)
    {
        v.push_back({p[i].first,p[i].second});
    }
    sort(v.begin(),v.end());
    vector<int> dp(n+1,-1);
    
    return solve(v,n,prev,dp);
    
}