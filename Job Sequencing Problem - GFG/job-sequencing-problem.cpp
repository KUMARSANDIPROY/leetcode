// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    bool static comp(Job a,Job b)
    {
        // if(a.profit>b.profit) return true;
        // else if(a.profit==b.profit) return a.dead<b.dead;
        // else if(a.profit<b.profit) return false;
        return a.profit>b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,comp);
        int start=0;
       // int finish=1;
        int maxdead=0;
        int count=0;
        //int ans=arr[0].profit;
        int ans=0;
     
        
        for(int i=0;i<n;i++)
        {
            maxdead=max(maxdead,arr[i].dead);
        }
        
        vector<int> temp(maxdead+1,-1);
        vector<int>res;
        for(int i=0;i<n;i++)
        {
            int j=arr[i].dead;
            while(temp[j]!=-1 && j>=1)
            {
                j--;
            }
            if(j>=1 && temp[j]==-1)
            {
                ans+=arr[i].profit;
                count++;
                temp[j]=arr[i].id;
            }
        }
        
        res.push_back(count);
        res.push_back(ans);
        
        return res;
        
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends