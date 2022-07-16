class Solution {
public:
    string minWindow(string s, string p) {
        map<char,int> mp1,mp2;
        
        for(int i=0;i<p.length();i++)
        {
            mp1[p[i]]++;
        }
        
        int dmcnt=p.length();
        int mcnt=0;
        int i=-1,j=-1;
        string  ans="";
        
        while(true)
        {   
            bool flag1=false,flag2=false;
             //cout<<j<<" "<<s.length()<<" "<<mcnt<<" "<<dmcnt;
             //if(j+1<s.length() && mcnt<dmcnt)  cout<<"yes ";
            while(j+1<s.length() && mcnt<dmcnt)
            {
                   
           
                j++;
                mp2[s[j]]++;
                if(mp1[s[j]]>=mp2[s[j]])
                    mcnt++;
                
                flag1=true;    
            }
          
            while(i<j && mcnt==dmcnt)
            {
                cout<<i<<j<<"starr  ";
                string temp=s.substr(i+1,j-i);
                if(ans.length()==0 || temp.length()<ans.length())
                  {
                    ans=temp;
                    // cout<<i<<j<<"ans  ";
                   
                }
                 
                i++;
                mp2[s[i]]--;
               // cout<<s[i];
                // cout<<mp1[s[i]]<<mp2[s[i]];
                if(mp1[s[i]]>mp2[s[i]])
                {
                    mcnt--;
                    //cout<<"mcnt"<<mcnt<<i<<j<<s[i]<<endl;
                }    
                
                flag2=true;    
                    
            }
            if(flag1==false && flag2==false) break;
        }
        return ans;
        
    }
};