class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n=temperatures.size();
        vector<int> v(n,0);
        stack<int> st;
        
        st.push(n-1);
        
        for(int i=n-2;i>=0;i--)
        {
           if(temperatures[i]<temperatures[st.top()])
           {
               v[i]=st.top()-i;
               st.push(i);
           }
            else
            {
              while(!st.empty() && temperatures[st.top()]<=temperatures[i])
              {
                  st.pop();
              }
                if(st.empty()==false)
                    v[i]=st.top()-i;
                st.push(i);
            }
        }
        return v;
        
        
        
    }
};