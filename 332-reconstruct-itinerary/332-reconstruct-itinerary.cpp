class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets)
    {
        
        map<string,multiset<string>> mp;
        
        vector<string> ans;
        
        stack<string> st;
        
        for(int i=0;i<tickets.size();i++)
        {
            mp[tickets[i][0]].insert(tickets[i][1]);
        }
        
        st.push("JFK");
    
        
        while(!st.empty())
        {
            string temp=st.top();
            
           
            
            if(mp[temp].size()==0)
            {
                ans.push_back(temp);
                st.pop();
                
            }
            else
            {
                auto t=mp[temp].begin();
                st.push(*t);
                mp[temp].erase(t);
            }
             
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};