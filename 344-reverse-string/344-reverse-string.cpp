class Solution {
public:
    void solve(vector<char> &s,int i,int j)
    {
        if(i>=j)
            return;
        swap(s[i],s[j]);
        solve(s,++i,--j);     
             
    
    }
    void reverseString(vector<char>& s)
    {
        int size=s.size();
        int i=0,j=size-1;
        solve(s,i,j);
        
    }
};