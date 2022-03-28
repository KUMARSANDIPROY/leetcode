// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
   
    bool subsetsum(int arr[],int n,int sum)
    {
        bool T[n+1][sum+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(i==0) T[i][j]=false;
                if(j==0) T[i][j]=true;
            }
        }
         for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
               if(arr[i-1]<=j)
                  T[i][j]=T[i-1][j-arr[i-1]] || T[i-1][j];
               else
               T[i][j]=T[i-1][j];
               
            }
        }
        return T[n][sum];
        
        
    }
  
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++ )
	       sum+=arr[i];
	       
	    int sum1=sum/2;
	    while(sum1>=0)
	    {
	        if(subsetsum(arr,n,sum1))
	        break;
	        sum1--;
	    }
	    int sum2=sum-sum1;
	    return abs(sum1-sum2);
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
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends