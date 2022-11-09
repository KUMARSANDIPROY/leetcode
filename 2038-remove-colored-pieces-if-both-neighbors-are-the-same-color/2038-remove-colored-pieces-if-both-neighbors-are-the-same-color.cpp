class Solution {
public:
    bool winnerOfGame(string colors) {
        
        int a=0;
        int b=0;
        int p1=0;
        int p2=0;
        int n=colors.length();
        
        char prev=colors[0];
        if(prev=='A') a++;
        else b++;
        for(int i=1;i<n;i++)
        {
            if(colors[i]==prev)
            {
                if(colors[i]=='A')
                    a++;
                else
                    b++;
            }
            else
            {
                if(prev=='A')
                {
                    p1+=max(0,(a-2));
                    prev='B';
                    a=0;
                    b=1;
                }
                else
                {
                    p2+=max(0,(b-2));
                    prev='A';
                    a=1;
                    b=0;
                }
                    
            }
            
        }
        if(prev=='A') p1+=max(0,(a-2));
        else p2+=max(0,(b-2));
        
        cout<<p1<<p2<<"  ";
        if(p1==p2 || p2>p1)  return false;
        else  return true;
    }
};