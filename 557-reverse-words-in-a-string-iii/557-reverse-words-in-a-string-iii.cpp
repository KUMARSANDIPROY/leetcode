class Solution {
public:
    string reverseWords(string s) 
    {
        int l=s.size();
        cout<<"length "<<l<<endl;
       
       int k=0;
       while(k<l)
       {
           int i=k,j=k,temp;
           while(s[j+1]!=' ' && j+1<l)
           {
               j++;
           }
           temp=j;
           //cout<<j<<" ";
           while(i<j)
               swap(s[i++],s[j--]);
           k=temp+2;
           cout<<k<<" ";
           
           
       }
        
        
        return s;
    }
};