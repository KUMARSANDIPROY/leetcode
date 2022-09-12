class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int,int>> q;
        int ans=INT_MIN;
        int n=points.size();
        
        for(int i=0;i<n;i++)
        {
            while(!q.empty() && abs(q.top().second-points[i][0])>k)
                q.pop();
            if(!q.empty())
                ans=max(ans,points[i][0]+ points[i][1] + q.top().first);
            
            q.push({points[i][1]-points[i][0],points[i][0]});
        }
        return ans;
    }
};