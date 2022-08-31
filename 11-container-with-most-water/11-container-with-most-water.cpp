class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1;
        int res=0;
        
        while(i<j)
        {
            int temp=min(height[i],height[j])*(j-i);  
          //  cout<<temp<<" ";
            res=max(temp,res);
            if(height[i]<height[j])
            {
                i++;
            }
            else j--;
        }
       
        return res;
        
    }
};