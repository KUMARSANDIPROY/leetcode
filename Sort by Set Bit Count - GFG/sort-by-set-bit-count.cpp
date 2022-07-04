// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int count_set_bits(int x)
    {
        int count=0;
        while(x>0)
        {
            if(x%2) 
               count++;
            x=x/2;   
        }
        return count;
    }
    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        map<int,vector<int> > mp;
        int no_set_bits;
        int mx=INT_MIN;
        int mn=INT_MAX;
        for(int i=0;i<n;i++)
        {
            no_set_bits=count_set_bits(arr[i]);
           // cout<<arr[i]<<"y"<<no_set_bits<<"  ";
            mp[no_set_bits].push_back(arr[i]);
            mx=max(mx,no_set_bits);
            mn=min(mn,no_set_bits);
        }
        //cout<<mn<<mx<<endl;
        // for(auto it:mp[1])
        //   cout<<it<<" ";
        //   cout<<endl;
         int idx=0;
        for(int i=mx;i>=mn;i--)
        {
            if(mp.count(i))
            {
                for(auto &it:mp[i])
                {
                  //  cout<<it<<" ";
                    arr[idx++]=it;
                    
                }
               // cout<<endl;
            }
        }
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends