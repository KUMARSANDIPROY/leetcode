class Solution {
public:
    int maxi = 0;
    int maxLength(vector<string> arr) {
        dfs(0, arr, "");
        return maxi;
    }
    
     void dfs(int start, vector<string> arr, string str){
        if(!isUnique(str)){
            return;
        }
         int sz=str.size();
        maxi = max(maxi, sz);
        
        for(int i=start; i<arr.size();i++){
            string s = arr[i];
            dfs(i+1, arr, str + s);
        }
    }
    
     bool isUnique(string s){
        set<char> st;
        
        for(char ch: s){
            if(st.find(ch)!=st.end()){
                return false;
            }
            st.insert(ch);
        }
        return true;
    }
};