class Solution {
public:
    string simplifyPath(string path) 
    {
        stack<string> st;
        
        for(int i=0;i<path.length();i++)
        {
            if(path[i]=='/')  continue;
            
            string temp="";
            while(path[i]!='/' && i<path.length())
                temp+=path[i++];
            
            if(temp==".") continue;
            if(temp=="..") 
            {
                if(st.empty()==false)
                    st.pop();
            }
            else
                st.push(temp);
        }
        
        string res="";
       
        while(st.empty()==false)
        {
             res="/" + st.top() + res;
             st.pop();
        }
        if(res=="") return "/";   
        
            
        return res;
    }
};