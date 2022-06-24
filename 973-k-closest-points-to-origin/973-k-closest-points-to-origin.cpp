class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        int n=points.size();
        priority_queue<tuple<double,int,int>> q;
        for(int i=0;i<n;i++)
        {
            int x=points[i][0];
            int y=points[i][1];
            
            long long sqr=x*x + y*y;
            double dist=sqrt(sqr);
            q.push(make_tuple(dist,x,y));
            if(q.size()>k) q.pop();
        }
        vector<vector<int>> res;
        while(q.empty()==false)
        {
            vector<int> v(2);
            tuple<double,int,int> t;
            t=q.top();
            q.pop();
            v[0]=get<1>(t);
            v[1]=get<2>(t);
            
            res.push_back(v);
        }
        return res;
    }
};