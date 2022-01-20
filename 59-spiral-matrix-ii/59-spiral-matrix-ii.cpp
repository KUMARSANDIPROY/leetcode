class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int top,down,right,left;
        vector<vector<int>> matrix(n,vector<int>(n));
        top=0;
        down=n-1;
        left=0;
        right=n-1;
        int count=0,number=1;
        
        while(top<=down && left<=right)
        {
            if(count==0)
            {   
                
                for(int i=left;i<=right;i++)
                    matrix[top][i]=number++;
                
                top++;
               // cout<<top<<down<<"TD"<<number<<"N ";
               
                count=(count+1)%4;
                
              }
            else if(count==1)
            {
                //cout<<top<<number<<"c1 " ;
                for(int i=top;i<=down;i++)
                    matrix[i][right]=number++;
                
                right--;
                count=(count+1)%4;
                //cout<<left<<right<<"LR1 ";
             }
            else if(count==2)
            {
                
                for(int i=right;i>=left;i--)
                   matrix[down][i]=number++;
                
                down--;
                 count=(count+1)%4;
            }
            
            else if(count==3)
            {
                 
                for(int i=down;i>=top;i--)
                    matrix[i][left]=number++;
                
                left++;
                count=(count+1)%4;
                //cout<<left<<right<<"LR3 ";
            }
        }
        return matrix;
        
    }
};