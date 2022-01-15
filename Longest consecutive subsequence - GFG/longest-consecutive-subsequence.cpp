// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
          map<int,int> mp;
          int count=1,res=1,prev;
          for(int i=0;i<N;i++)
          {
              mp[arr[i]]=1;
          }
        
         auto temp=mp.begin();
         prev=temp->first;
         temp++;
         for(auto it=temp;it!=mp.end();it++)
         {
            
                if(it->first==prev+1) count++;
                else count=1;
              
                 prev=it->first;
                 res=max(res,count);
         }
          return res;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends