// { Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
#include <bits/stdc++.h>


class Solution{   
public:
    int minimumStep(int n){
        //complete the function here
        //int count =ceil(log(n)/log(3));
        int count=0;
        while(n>1)
        {
            if(n%3==0)
            {
                count++;
                n/=3;
            }
            else
            {
                count++;
                n--;
            }
        }
        
        return count;
        
        return count;
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
        cin >> n;
        Solution ob;
        cout << ob.minimumStep(n) << endl;
    
    }
    return 0; 
} 

  // } Driver Code Ends