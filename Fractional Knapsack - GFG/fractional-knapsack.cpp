// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    bool static comp(pair<double,int> a,pair<double,int> b)
    {
        return a.first>b.first;
    }
    
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double,int>> temp;
        
        for(int i=0;i<n;i++)
        {
            float x=(double)arr[i].value/(double)arr[i].weight;
            temp.push_back({x,i});
        }
        
        sort(temp.begin(),temp.end(),comp);
        
        int i=0;
        double ans=0;
        while(W>0 && i<n)
        {
            int index=temp[i++].second;
            if(W>=arr[index].weight)
            {
                ans+=arr[index].value;
                W-=arr[index].weight;
               // cout<<W<<"W  ";
            }
            
            else
            {
              //  cout<<ans;
              //  cout<<W<<"u   ";
                double fraction=(double)W/(double)arr[index].weight;
                //cout<<fraction<<"frac  ";
                ans=ans+(arr[index].value * fraction);
                break;
            }
        }
        return ans;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends