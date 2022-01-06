class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int r=board.size(),c=board[0].size();
        map<string,int> mp1,mp2,mp3;
        
        for(int p=0;p<r;p++)
        {
            
            for(int q=0;q<c;q++)
            {
                string s=to_string(q);
               // cout<<s;
                int box=(p/3)*3+q/3;
                if(board[p][q]!='.')
                {
                    string s1=to_string(p)+to_string(board[p][q]);
                    string s2=to_string(box)+ to_string(board[p][q]);
                    string s3=to_string(q)+to_string(board[p][q]);
                   // cout<<s1<<" ";
                   // cout<<box<<" ";
                    if(mp1[s1]!=0 || mp2[s2]!=0 || mp3[s3]!=0) return false;
                    else
                    {
                        mp1[s1]++;
                        mp2[s2]++; 
                        mp3[s3]++;
                    }
                }

            }
          
           
        }
       
        return true;
        
    }
};