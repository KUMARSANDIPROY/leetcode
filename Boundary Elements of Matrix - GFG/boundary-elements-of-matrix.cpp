//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    vector<int> BoundaryElements(vector<vector<int>>&matrix){
        // Code here
        
        vector<int> v;
        
        int row=matrix.size();
        int col=matrix[0].size();
        
        for(int i=0;i<col;i++)
           v.push_back(matrix[0][i]);
        
        for(int i=1;i<row-1;i++)
        {
            v.push_back(matrix[i][0]);
            v.push_back(matrix[i][col-1]);
        }
        
        if(row>1)
        {
            for(int i=0;i<col;i++)
              v.push_back(matrix[row-1][i]);
        }
        
      
           
       
           return v;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		Solution obj;
		vector<int>ans = obj.BoundaryElements(matrix);
		for(auto i: ans)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends