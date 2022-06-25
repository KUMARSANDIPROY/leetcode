// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        vector<int> res;
        vector<int> idx(K,0);
        
        for(int i=0;i<K;i++)
        {
            q.push({arr[i][0],i});
        }
        
        while(q.empty()==false) //res.size()<K*K)
        {
            int val=q.top().first;
            int arr_no=q.top().second;
            q.pop();
            res.push_back(val);
            idx[arr_no]++;
            if(idx[arr_no]<K)
              q.push({arr[arr_no][idx[arr_no]],arr_no});
        }
        
        while(!q.empty()){
            res.push_back(q.top().first);
            q.pop();
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends