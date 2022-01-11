class Solution {
public:
    static bool comp (vector<int> p1, vector<int> p2)
    {
         return p1[0] < p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]);
     }
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> v;
        int n=intervals.size();
        vector<int> temp;
        sort(intervals.begin(),intervals.end(),comp);
        
        int start=intervals[0][0];
        int end=intervals[0][1];
        for(int i=1;i<n;i++)
        {
            if(end<intervals[i][0])
            {
                 temp.push_back(start);
                temp.push_back(end);
                
                v.push_back(temp);
                temp.clear();
                start=intervals[i][0];
                end=intervals[i][1];
            }
            else if(end>=intervals[i][0])
            {
                start=min(intervals[i][0],start);
                end=max(intervals[i][1],end);
            }
                
        }
        temp.push_back(start);
        temp.push_back(end);
                
        v.push_back(temp);
        return v;
        
        
    }
};