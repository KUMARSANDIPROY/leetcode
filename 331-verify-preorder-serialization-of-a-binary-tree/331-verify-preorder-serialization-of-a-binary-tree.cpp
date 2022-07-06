class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<string> st;
        int l=preorder.size();
        for(int i=0;i<l-1;i++)
        {
            string s="";
            while(preorder[i]!=',' && i<l-2)
                s+=preorder[i++];
            if(st.empty())
            {
                if(s=="#")
                    return false;
                else
                    st.push(s);
            }
            else
            {
                if(s=="#")
                    st.pop();
                else
                    st.push(s);
            }
        }
       // cout<<"b,s";
        if(st.size()==0 && preorder[l-1]=='#')
            return true;
        
        else return false;
    }
};