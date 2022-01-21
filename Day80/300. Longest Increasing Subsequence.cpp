/*
Platform :- Leetcode
Approach :- We always have atleast a LIS of size '1' which will any item of arry itself , else if we are at 'ith' index then we will go to all the preceding 'j' from (0 to i-1)
            and  if ( arr[i] >  arr[j] ) then we have a LIS till 'i' as LIS[i] = max (LIS[i-1] + 1, LIS[i] ).
            At the end we return the max value out of it .
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans=1;
        int n = nums.size();
        vector<int>dp(n);
        for(int i=0;i<nums.size();++i){
            dp[i]=1;
            for(int j=0;j<i;++j){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                    ans=max(ans,dp[i]);
                }
            }
        }
        
        return ans;
    }
};
