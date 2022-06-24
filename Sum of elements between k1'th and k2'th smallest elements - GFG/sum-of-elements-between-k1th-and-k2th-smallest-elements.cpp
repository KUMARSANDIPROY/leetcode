// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int kthSmallest(long long A[],long long N,long long K)
    {
        priority_queue<long long> q;
        
        for(long long i=0;i<N;i++)
        {
            q.push(A[i]);
            
            if(q.size()>K)
               q.pop();
        }
        
        return q.top();
    }
    
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        long long x=kthSmallest(A,N,K1);
        long long y=kthSmallest(A,N,K2);
        
        long long sum=0;
        
        for(long long i=0;i<N;i++)
        {
            if(A[i]>x && A[i]<y)
               sum+=A[i];
        }
        return sum;
    }
};

// { Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}
  // } Driver Code Ends