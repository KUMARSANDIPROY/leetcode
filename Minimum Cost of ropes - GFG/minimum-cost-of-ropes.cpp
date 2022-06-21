// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        
        priority_queue<long long,vector<long long>,greater<long long>> q;
        for(long long i=0;i<n;i++)
        {
            q.push(arr[i]);
        }
        
        long long sum=0;
        while(q.size()>1)
        {
            long long x=q.top();
            q.pop();
            long long y=q.top();
            q.pop();
            
            sum+=x+y;
            //cout<<x+y<<"  ";
            q.push(x+y);
        }
        return sum;
    }
};


// { Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends