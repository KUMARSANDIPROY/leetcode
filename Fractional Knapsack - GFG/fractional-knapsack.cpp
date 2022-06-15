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
    bool static cmp(Item a,Item b)
    {
        double x=(double)a.value/(double)a.weight;
        double y=(double)b.value/(double)b.weight;
        
        return x>y;
    }
    
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,cmp);
        double ans=0;
        
        int i=0;
        while(W>0 && i<n)
        {
            if(W>=arr[i].weight)
            {
                ans+=arr[i].value;
                W-=arr[i].weight;
                i++;
                
            }
            else if(W<arr[i].weight)
            {
                double fraction=(double)W/(double)arr[i].weight;
                ans+=(double)arr[i].value*(double)fraction;
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