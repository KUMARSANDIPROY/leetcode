// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool static cmp(pair<int,int> a,pair<int,int>b)
   {
       return a.first<b.first;
   }
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        vector<pair<int,int>> v;
       //cout<<k;
        for(int i=0;i<n;i++)
        {
            v.push_back({price[i],i+1});
        }
        sort(v.begin(),v.end(),cmp);
      
        int count=0;
        //cout<<"jhbv";
        for(int i=0;i<n;i++)
        {
             
            if(k<v[i].first) break;
            if(k>=v[i].first)
            {
                
              //  cout<<v[i].second<<"indx  ";
                int times=k/v[i].first;
               // cout<<times<<"ti ";
                if(times>v[i].second)
                {
                  //  cout<<v[i].second<<"indx  ";
                   //` cout<<v[0].first<<k<<" ";
                    count+=v[i].second;
                   // cout<<count<<"cnt  ";
                    k=k-v[i].second*v[i].first;
                }
                else
                {
                    count+=times;
                    k=k-times*v[i].first;
                    break;
                }
            }
        }
        return count;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends