class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        priority_queue<pair<int,int>> q;// diff,index;
        
        for(int i=0;i<arr.size();i++)
        {
            q.push({abs(arr[i]-x),i});
            
            if(q.size()>k)
                q.pop();
        }
        
        vector<int> res;
        
        while(q.empty()==false)
        {
            res.push_back(arr[q.top().second]);
            q.pop();
        }
        
        sort(res.begin(),res.end());
        
        return res;
    }
};