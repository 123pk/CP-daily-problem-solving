/*
Platform :- Leetcode
Approach :- Find LIS and LDS for each of the index , if LIS and LDS for each any index >=2 then the we can have a mountain sequence of size (LIS[i]+LDS[i])-1 , at the end we need 
            to find number of items we need to remove and that are going to be ( n - size_of_longest_mountain_sequence)
*/
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int ans=0;
        
        //Find LIS for each index 
        //Find LDS for each index
        // LIS[i]+LDS[i]-1 , max of all is our answer
        
        int n=nums.size();
        vector<int>lis(n),lds(n);
        
        for(int i=0;i<n;++i){
            lis[i]=1;
            for(int  j=0;j<i;++j){
                if(nums[i]>nums[j]){
                    lis[i]=max(lis[j]+1,lis[i]);
                }
            }
        }
        
        for(int i=n-1;i>=0;--i){
            lds[i]=1;
            for(int j=n-1;j>i;--j){
                if(nums[i]>nums[j]){
                    lds[i]=max(lds[i],lds[j]+1);
                }
            }
        }
        
        //now find the max for all the n values
        for(int i=0;i<n;++i){
           // cout<<lis[i]<<" "<<lds[i]<<" for "<<nums[i]<<"\n";
            if(lis[i]>=2 && lds[i]>=2){
                ans=max(ans,lis[i]+lds[i]-1);
            }
        }
        
        return n-ans;
    }
};
