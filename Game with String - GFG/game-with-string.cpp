// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        map<char,int> mp;
        for(int i=0;i<s.length();i++)
           mp[s[i]]++;
           
        priority_queue<int> q;
        for(auto i:mp)
        {
            q.push(i.second);
        }
        for(int i=0;i<k;i++)
        {
            int temp=q.top();
            q.pop();
            temp--;
            q.push(temp);
        }
        priority_queue<int> q1=q;
        int l=q.size();
        
        int sum=0;
        
        for(int i=0;i<l;i++)
        {
         
            sum=sum+pow(q.top(),2);
            q.pop();
        }
        return sum;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}  // } Driver Code Ends