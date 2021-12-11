/*
Platform :- Leetcode
Contest :- Leetcode Bi weekly contest 67
Approach :- Since we need to choose subsequence we will simply choose the largest k elements of array in ascending order of index
*/
bool comp(pair<int,int>&P,pair<int,int>&Q){
    if(P.first==Q.first)return P.second<Q.second;
    return P.first>Q.first;
}

bool comp2(pair<int,int>&P,pair<int,int>&Q){
    return P.second<Q.second;
}

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>>P,Q;
        for(int i=0;i<nums.size();++i){
            P.push_back({nums[i],i});
        }
        
        sort(P.begin(),P.end(),comp);
        vector<int>ans;
        
        for(int i=0;i<k;++i)Q.push_back(P[i]);
        sort(Q.begin(),Q.end(),comp2);
        
        for(auto &x:Q)ans.push_back(x.first);
        
        return ans;
    }
};
