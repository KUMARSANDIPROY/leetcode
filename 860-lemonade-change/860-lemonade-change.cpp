class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        if(bills[0]!=5) return false;
        int n=bills.size();
        int ten=0;
        int five=0;
        
        for(int i=0;i<n;i++)
        {
            if(bills[i]==5)
                five++;
            else if(bills[i]==10)
            {
                ten++;
                if(five>0)
                    five--;
                else 
                    return false;
            }
            else if(bills[i]==20)
            {
                if(ten>0 && five>0)
                {
                    ten--;
                    five--;
                }
                else if(five>2)
                {
                    five=five-3;
                }
                else return false;
            }
            cout<<five<<"  "<<ten<<endl;
        }
        return true;
    }
};