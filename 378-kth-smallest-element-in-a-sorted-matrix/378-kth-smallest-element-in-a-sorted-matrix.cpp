class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
       
        int low=matrix[0][0];
        int row=matrix.size();
        int col=matrix[0].size();
        int high=matrix[row-1][col-1];
        int ans;
        while(low<=high)
        {
            int mid=low + (high-low)/2;
           
            int count=0;
            for(int i=0;i<row;i++)
            {
                count+=upper_bound(matrix[i].begin(),matrix[i].end(),mid) - matrix[i].begin();
                
            }
             cout<<mid<<"  "<<count<<endl;
            if(count>=k)
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};