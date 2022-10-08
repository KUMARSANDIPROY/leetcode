class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& h)
    {
        int n=h.size();
        vector<int>a(n,0);
        stack<int>s;
        s.push(h[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            while(!s.empty()&&h[i]>s.top())
            {
               s.pop();
                a[i]++;
                
            }
            if(!s.empty())a[i]++;
            
            s.push(h[i]);
        }
        return a;
    }
};