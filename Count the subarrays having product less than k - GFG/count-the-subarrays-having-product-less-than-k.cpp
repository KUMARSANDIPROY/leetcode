// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& nums, int n, long long k) {
        
        if(k<=1) return 0;
        
        int left=0;
        int right=0;
        long long prod=1;
        long long count=0;
       
        while(right<nums.size())
        {
            prod*=nums[right];
            
            while(prod>=k)
                prod/=nums[left++];
        
            count+=right-left+1;
            right++;
        }
        
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends