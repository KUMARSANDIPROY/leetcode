// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N){
        //Write your code here
        int v_cuts=1;
        int h_cuts=1;
        
        sort(X.begin(),X.end(),greater<int>());
        sort(Y.begin(),Y.end(),greater<int>());
        
        int i=0,j=0;
        int res=0;
        while(i<M && j<N)
        {
            if(X[i]>Y[j])
            {
               res+=v_cuts*X[i++];
               h_cuts++;
            }
            else
            {
                res+=h_cuts*Y[j++];
                v_cuts++;
            }
        }
        
        while(i<M)
        {
            res+=v_cuts* X[i++];
            h_cuts++;
        }
        while(j<N)
        {
            res+=h_cuts * Y[j++];
            v_cuts++;
        }
        return res;
    }
};



// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int m, n;
	    cin >> m >> n;
	    vector<int>X(m - 1), Y(n - 1);
	    for(int i = 0; i < m - 1; i++){
	        cin >> X[i];
	    }
	    for(int i = 0; i < n - 1; i++){
	        cin >> Y[i];
	    }
	    Solution ob;
	    int ans = ob.minimumCostOfBreaking(X, Y, m - 1, n - 1);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends