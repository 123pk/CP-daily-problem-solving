/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 275
Approach :- Append the current array to the end of it , nums+nums , now store the no of ones till ith index using prefix array , also count no of ones in original array , since we
            need to group them together , let c = total_no_of_ones in original array then we want to choose that subarray of size 'c' where no of '0' isminimum and that is our ansewr
            because we need to replace 0s .
*/
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        int start=0,end=0;
        vector<pair<int,int>>ones;
        
      
        int n=nums.size();
        int d=0;
        vector<int>z(2*n);
        for(int i=0;i<nums.size();++i){
            d+=nums[i];
            z[i]=d;
        }
        int c=d;
        
        for(int i=0;i<n;++i){
            d+=nums[i];
            z[n+i]=d;
        }
        
        //now pair of c
        if(c==0)return 0;
        
        int ans=c-z[c-1];
        
        for(int i=c;i<(2*n);++i){
            ans=min(ans,c-(z[i]-z[i-c]));
        }
        
        return ans;
        
    }
};
