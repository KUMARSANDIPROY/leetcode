// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        
        int lm[n];//stores the left max element
        int rm[n];//stores the right mnost element
        int lmax=0;
        for(int i=0;i<n;i++)
        {
           
          if(lmax<arr[i])
             lmax=arr[i];
        lm[i]=lmax;     
          
        }
       // cout<<endl;
       int rmax=0;
          for(int i=n-1;i>=0;i--)
        {
            
           if(rmax<arr[i])
              rmax=arr[i];
           rm[i]=rmax;      
        }
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            int x=min(lm[i],rm[i]);
            int d=x-arr[i];
            //cout<<d<<" ";
            if(d>0)
            sum+=d;
        }
        
        
        return sum;
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