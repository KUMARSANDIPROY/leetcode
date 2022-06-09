// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<long long> st;
        
        vector<long long> res(arr.size(),-1);
  
        st.push(0);

        for(int i=1;i<arr.size();i++)
        {
  
            if(arr[i]<arr[st.top()])
               st.push(i);
               
            else
            {
                while(st.empty()==false && arr[i]>arr[st.top()])
                {
                    res[st.top()]=arr[i];
                    st.pop();
                }
                st.push(i);
                
            }    
        }
    
        
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends