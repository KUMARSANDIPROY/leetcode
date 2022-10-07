class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
       long long ans = 0;
        vector<int> v;
        int st = 0;
        int cnt = 2;
        if(nums.size() == 1){
            st = nums[0];
        }
        else{
            st = nums[1] - nums[0];
        }
        for(int i = 2 ; i < nums.size() ; i++){
              if(nums[i] - nums[i-1] == st){
                  cnt++;
              }
              else{
                  st = nums[i] - nums[i-1];
                  if(cnt >=3){
                      v.push_back(cnt);
                  }
                  cnt = 2;
              }
        }
        v.push_back(cnt);
        for(auto vv: v){
            ans+= ((vv-2)*(vv-1))/2;   
        }
        return ans;
    }
    
};