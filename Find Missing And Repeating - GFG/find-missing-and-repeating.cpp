// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int i=0;
        int dup,mis;
        
        while(i<n)
        {
            if(i+1!=arr[i])
            {
                if(arr[i]==arr[arr[i]-1])
                   i++;
                 else if(arr[i]!=arr[arr[i]-1])
                   swap(arr[i],arr[arr[i]-1]); 
                
            }
            else if(i+1==arr[i])
              i++;
        }
        
        int *res=new int[2];
        for(int i=0;i<n;i++)
        {
            if(i+1!=arr[i])
            {
               dup=arr[i];
               mis=i+1;
            }
        }
        res[0]=dup;
        res[1]=mis;
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends