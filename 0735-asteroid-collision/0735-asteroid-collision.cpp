class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        
        vector<int> st;
        for(int i:ast)
        {
            while(st.empty()==false && st.back()>0 && st.back()<-i)
               st.pop_back();
            
            if(st.empty() || i>0 || st.back()<0)
                st.push_back(i);
            else if(i<0 && st.back()==-i)
                st.pop_back();
        }
        return st;
    }
};