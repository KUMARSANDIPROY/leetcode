// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
#include<algorithm>
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long result=arr[0],temp;
	    long long max_till_now=arr[0];
	    long long min_till_now=arr[0];
	    for(int i=1;i<n;i++)
	    {
	        temp=max_till_now;
	        max_till_now=max(arr[i]*max_till_now,arr[i]*min_till_now);
	     
	        if(max_till_now<arr[i])
	           max_till_now=arr[i];
	        min_till_now=min(arr[i]*temp,arr[i]*min_till_now);
	        if(min_till_now>arr[i])
	           min_till_now=arr[i];
	        result=max(max_till_now,result);
	        
	    }
	    return result;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends