// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
         int top=0;
         int down=matrix.size()-1;
         int left=0;
         int right=matrix[0].size()-1;
         int count=0;
         vector<int> v;
         
         while(left<=right && top<=down)
         {
            if(count==0)    
            {
                for(int i=left; i<=right;i++)
                {
                    v.push_back(matrix[top][i]);
                   
                }
                 count=(count+1)%4;
                 top++;
            }
            else if(count==1)
            {
                for(int i=top;i<=down;i++)
                {
                    v.push_back(matrix[i][right]);
                }
                 count=(count+1)%4;
                 right--;
            }
            else if(count==2)
            {
                for(int i=right;i>=left;i--)
                {
                    v.push_back(matrix[down][i]);
                   
                }
                 down--;
                 count=(count+1)%4;
                    
            }
            else if(count==3)
            {
                for(int i=down;i>=top;i--)
                {
                    v.push_back(matrix[i][left]);
                }
                 
                count=(count+1)%4;
                left++;
                    
            }
            
             
         }
         return v;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends