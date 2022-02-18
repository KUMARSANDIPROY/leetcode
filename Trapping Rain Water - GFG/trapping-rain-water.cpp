// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        
        int lmax=arr[0];
        int rmax=arr[n-1];
        if(n<=2) return 0;
        
        int left=1;
        int right=n-2;
        long long res=0;
        
        while(left<=right)
        {
            if(lmax<=rmax)
            {
                if(lmax>=arr[left])
                {
                    res+=lmax-arr[left];
                    left++;
                    
                }
                else if(lmax<arr[left])
                {
                    lmax=arr[left];
                    left++;
                }
            }
            else if(lmax>rmax)
            {
                if(rmax>=arr[right])
                {
                    res+=rmax-arr[right];
                    right--;
                }
                else if(rmax<arr[right])
                {
                    rmax=arr[right];
                    right--;
                    
                }
                
            }
            
            
        }
        return res;
        
        
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends