/*
Platform :- Leetcode
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        vector<int>Q;
        int c=1;
        for(int i=0;i<nums.size();++i)
        { 
            if(i==(nums.size()-1))
            {  
                if(c==1)
                {
                    Q.push_back(nums[i]);
                }
                
            }
         else
         {
             if(nums[i]==nums[i+1])
             {
                 c++;
             }
             else
             {
                if(c==1)
                {
                 Q.push_back(nums[i]);
                 } 
                 else
                 {
                     c=1;
                 }
             }
             
             
         }
           
        }
        return Q;
    }
};
