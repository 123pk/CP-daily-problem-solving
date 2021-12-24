/*
Platform :- leetcode
Approach :- sorting + two pointer
*/
bool compare(vector<int>&P,vector<int>&Q)
{
    if(P[0]==Q[0])
    {
        return P[1]<Q[1];
    }
    return P[0]<Q[0];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        
        int start=intervals[0][0],end=intervals[0][1];
        vector<vector<int>>ans;
        for(int i=1;i<intervals.size();++i)
        {
            if(start<=intervals[i][0] && intervals[i][0]<=end )
            {
                start=min(start,intervals[i][0]);
                end=max(end,intervals[i][1]);
            }
            else
            {
                ans.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
            
        }
        ans.push_back({start,end});
        return ans;
        
        
    }
};
