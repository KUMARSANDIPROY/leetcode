// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    sort(arr,arr+n);
	    
	    long long count=0;
	    
	    for(int i=0;i<n;i++)
	    {
	        long long rem=sum-arr[i];
	        
	        int left=i+1,right=n-1;
	        
	        while(left<right)
	        {
	            if(rem==arr[left]+arr[right])
	            {
	              
	                right--;
	                
	            }
	            else if(rem>arr[left]+arr[right])
	            {
	                count+=right-left;
	                left++;
	            }
	            else
	               right--;
	        }
	    }
	    return count;
	}
		 

};

// { Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends