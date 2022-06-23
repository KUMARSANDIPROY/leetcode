// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int K) {
        // Your code goes here
        set<vector<int>> res;
        sort(arr.begin(),arr.end());
      
        for(int i=0;i<arr.size();i++)
        {
          
            
            for(int j=i+1;j<arr.size();j++)
            {
                int sum1=arr[i]+arr[j];
                int target=K-sum1;
                int p=j+1,q=arr.size()-1;
                
                while(p<q)
                {
                    if(target<(arr[p]+arr[q]))  q--;
                    else if(target>(arr[p]+arr[q])) p++;
                    
                    else if(target==(arr[p]+arr[q]))
                    {
                        //cout<<"hdgc";
                        vector<int> v(4);
                        v[0]=arr[i];
                        v[1]=arr[j];
                        v[2]=arr[p];
                        v[3]=arr[q];
                        res.insert(v);
                        p++;
                        q--;
                    }
                }
                
               
                
            }
           
        }
        vector<vector<int>>  final(res.begin(),res.end());
        return final;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends