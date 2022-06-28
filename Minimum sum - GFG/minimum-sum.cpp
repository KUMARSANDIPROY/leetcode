// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
 	string add(string str1, string str2){
   	    // Code here
   	    if(str1.length()<str2.length())
   	      swap(str1,str2);
   	      
   	    int l1=str1.size();
   	    int l2=str2.length();
   	    
   	    reverse(str1.begin(),str1.end());
   	    reverse(str2.begin(),str2.end());
   	    
   	    string res="";
   	    
   	    int carry=0;
   	    
   	    for(int i=0;i<l2;i++)
   	    {
   	        int x=((str1[i]-'0') + (str2[i]-'0') + carry);
   	        res+=to_string(x%10);
   	        carry=x/10;
   	    }
   	    
   	    for(int i=l2;i<l1;i++)
   	    {
   	        int x=(str1[i]-'0') + carry;
   	        carry=x/10;
   	        res+=to_string(x%10);
   	    }
   	   // cout<<res<<endl;
   	    if(carry>0)
   	      res+=to_string(carry);
   	    reverse(res.begin(),res.end());
   	    return res;
   	} 
    

    string solve(int arr[], int n) {
        // code here
        sort(arr,arr+n);
        string str1="";
        string str2="";
        
        for(int i=0;i<n;i+=2)
        {
            if(arr[i]!=0)    
               str1+=to_string(arr[i]);
            
            if(i+1<n && arr[i+1]!=0)
               str2+=to_string(arr[i+1]);
        }
      //  cout<<str1<<"  "<<str2<<endl;
       
       return add(str1,str2);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends