class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        for(int j=0;j<nums1.size();j++)
        {
           
           auto it=find(nums2.begin(),nums2.end(),nums1[j]);
           //cout<<nums1[j]<<" "; 
            it++;
            vector<int>::iterator i;
           for(i=it;i!=nums2.end();i++)
           {
               //cout<<*i<<nums1[j]<<" ";
               if(*i>nums1[j])
               {
                   v.push_back(*i);
                   break;
                }
           }
            if(i==nums2.end())
            {
             //   cout<<nums1[j];
                v.push_back(-1);
            }
            
        }
        return v;
        
        
    } 
    
};