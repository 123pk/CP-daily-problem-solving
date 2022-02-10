/*
Platform :- Leetcode
Approach :- Traverse through array and find that if (tot-k) is acheived earlier or not . 
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int c=0,tot=0;
        unordered_map<int,int>P;
        P[0]=1;
        for(int i=0;i<nums.size();++i)
        {
            tot+=nums[i];
            if(P[tot-k])
            {
                c+=P[tot-k];
            }
            P[tot]++;
        }
        return c;
    }
};
