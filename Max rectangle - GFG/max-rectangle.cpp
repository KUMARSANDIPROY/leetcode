// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
      vector<int> solve2(int  v[],int l)
    {
        vector<int> res;
    
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
    
    vector<int> solve1(int  v[],int l)
    {
        vector<int> res;
       // int l=v.size();
       // memset(res,l,sizeof(v));
       for(int i=0;i<l;i++)
          res.push_back(l);
        stack<int> st;
        st.push(0);
        for(int i=1;i<l;i++)
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

    
   int getMaxArea(int arr[], int n)
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
  
  
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int v[m];
        
        for(int i=0;i<m;i++)
        {
            v[i]=M[0][i];
        }
        int res=getMaxArea(v,m);
      //cout<<res<<endl;
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(M[i][j]==0)
                   v[j]=0;
                else
                   v[j]+=M[i][j];
            }
            int temp=getMaxArea(v,m);
            res=max(res,temp);
        }
        return res;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends