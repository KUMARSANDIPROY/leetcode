// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int p=0;
        int i=0,j=0;
        int res=-1;
        while(i<n && j<m)
        {
            p++;
           // cout<<p<<"  "; 
            if(arr1[i]<=arr2[j])
             {
                 res=arr1[i];
                 i++;
                 
             }
            
            else
            {
                res=arr2[j];
                j++;
            }
            if(p==k)
              return res;
                
        }
      
        while(i<n)
        {
            p++;
            res=arr1[i];
            if(p==k)
               return res;
            i++;   
        }
         while(j<m)
        {
             // cout<<j<<" j"<<endl;
            p++;
            res=arr2[j];
            if(p==k)
              return res;
              j++;
        }
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends