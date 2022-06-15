// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int nums[], int d, int n){
        // code here
       // int *nums=arr;
        int k=d;
        //int n=nums.size();
        while(n<=k)
            k=k-n;
        k=n-k;    
        if(n>1)
        {    
            int i=0,j=n-k-1;
            while(i<j)
            {
                swap(nums[i++],nums[j--]);
            }
            i=n-k,j=n-1;
            while(i<j)
            {
                swap(nums[i++],nums[j--]);

            }
            i=0,j=n-1;
            while(i<j)
            {
                swap(nums[i++],nums[j--]);
            }
        }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	//taking testcases
	cin >> t;
	
	while(t--){
	    int n, d;
	    
	    //input n and d
	    cin >> n >> d;
	    
	    int arr[n];
	    
	    //inserting elements in the array
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    //calling rotateArr() function
	    ob.rotateArr(arr, d,n);
	    
	    //printing the elements of the array
	    for(int i =0;i<n;i++){
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}  // } Driver Code Ends