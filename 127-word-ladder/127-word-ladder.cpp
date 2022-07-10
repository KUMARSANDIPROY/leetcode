class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> st;
        int l=wordList.size();
        bool is_present=false;
        
        for(int i=0;i<l;i++)
        {
            if(wordList[i]==endWord)
                is_present=true;
            st.insert(wordList[i]);
        }
        
        if(is_present==false)
            return 0;
        
        queue<string> q;
        int level=0;
        q.push(beginWord);
        st.erase(beginWord);
        
        while(q.empty()==false)
        {
            int n=q.size();
            level++;
            while(n--)
            {
                string word=q.front();
                q.pop();
                int m=word.size();
                for(int i=0;i<m;i++)
                {
                    string temp=word;
                    for(int c='a';c<='z';c++)
                    {
                         temp[i]=c;
                        
                        if(temp==endWord)
                            return level+1;
                        
                        if(st.find(temp)!=st.end())
                        {
                            q.push(temp);
                            st.erase(temp);
                        }
                    }
                }
            }
            
        }
        return 0;
    }
};