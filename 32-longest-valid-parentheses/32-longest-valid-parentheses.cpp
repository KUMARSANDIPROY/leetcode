class Solution {
public:
    //https://youtu.be/qC5DGX0CPFA
    int longestValidParentheses(string s) {
        
        stack<char> charst;
        stack<int> indexst;
        indexst.push(-1);
        int len=0;
     //   if(s.length()<=1) return 0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                charst.push('(');
                indexst.push(i);
            }
            else if(s[i]==')')
            {
                if(!charst.empty())// && charst.top()=='(')
                {
                    charst.pop();
                    indexst.pop();
                    len=max(len,i-indexst.top());
                }
                else if(charst.empty())
                {
                    indexst.push(i);
                }
            }
        }
        return len;
    }
};