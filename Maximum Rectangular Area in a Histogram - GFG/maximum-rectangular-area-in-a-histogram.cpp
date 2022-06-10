// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    
vector<int> solve2(long long  v[],int l)
{
    vector<int> res;
  //  int l=v.size();
   // memset(res,l,sizeof(v));
   for(int i=0;i<l;i++)
      res.push_back(-1);
    stack<int > st;
    st.push(l-1);
    for(int i=l-2;i>=0;i--)
    {
        if(!st.empty() &&v[i]>v[st.top()])
           st.push(i);
           
        else
        {
            while(!st.empty() && v[i]<v[st.top()])
            {
                res[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
    }
    // for(int i=0;i<l;i++)
    //   cout<<res[i]<<" ";
    
    return res;
}

vector<int> solve1(long long  v[],int l)
{
    vector<int> res;
   // int l=v.size();
   // memset(res,l,sizeof(v));
   for(int i=0;i<l;i++)
      res.push_back(l);
    stack<int> st;
    st.push(0);
    for(int i=0;i<l;i++)
    {
        if(!st.empty() &&v[i]>v[st.top()])
           st.push(i);
           
        else
        {
            while(!st.empty() && v[i]<v[st.top()])
            {
                res[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
    }
    // for(int i=0;i<l;i++)
    //   cout<<res[i]<<" ";
    
    return res;
}

    
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
    vector<int> nextSmaller,prevSmaller;
    nextSmaller=solve1(arr,n);
   
    prevSmaller=solve2(arr,n);
    
    long long res=INT_MIN;
    for(int i=0;i<n;i++)
    {
        long long temp=(nextSmaller[i] - prevSmaller[i]-1)*arr[i];
        res=max(res,temp);
    }
    return res;
    
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends