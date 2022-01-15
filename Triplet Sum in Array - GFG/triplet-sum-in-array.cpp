// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        int fp,bp,rem_sum;
        sort(A,A+n);
       for(int i=0;i<n;i++)
       {
           rem_sum=X-A[i];
           fp=i+1;
           bp=n-1;
          
           while(fp<bp)
           {
               
               if(rem_sum==A[fp]+A[bp])
                  return true;
               else if(rem_sum<A[fp]+A[bp])  
                   bp--;
               else if(rem_sum>A[fp]+A[bp])   
                   fp++;
                   
           }
           
       }
       return false;
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends