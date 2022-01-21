class Solution {//LOVE BABBAR  https://www.youtube.com/watch?v=tWnHbSHwNmA&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=42
public:
    void solve(string digits,string mapping[],vector<string> &ans,string output,int index)
    {
        if(index>=digits.length())
        {
            ans.push_back(output);
            return;
        }
        int number=digits[index]-'0';
        string s=mapping[number];
        for(int i=0;i<s.length();i++)
        {
            output+=s[i];
            solve(digits,mapping,ans,output,index+1);
            output.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output="";
        int index=0;
        if(digits.length()==0)
          return ans;
        string mapping[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,mapping,ans,output,index);
        return ans;
        
    }
};