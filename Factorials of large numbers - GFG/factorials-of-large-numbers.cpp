// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int N){
        // code here
        vector<int> v;
        int c=0,flag=0;
        v.push_back(1);
        for(int i=2;i<=N;i++)
        {  
            flag=0;
            for(int j=0;j<v.size();j++)
            {
                 int x=i*v[j]+c;
                 c=0;
               
                
                // if(x>=10)
                 {
                     v[j]=(x%10);
                     c=x/10;
                     
                 }
              
                
                 if(j==v.size()-1 && c>0)
                 {
                   
                     while(c>0)
                     {
                         v.push_back(c%10);
                         c/=10;
                         flag=1;
                     }
                      
                 }
                   
                 if(flag==1) break;
               
            }
            
               
        }
        reverse(v.begin(),v.end());
        
        return v;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends