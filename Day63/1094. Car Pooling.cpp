/*
Platform :- Leetcode
Approach :- We maintain a frequency where we add capacity[i] passengers on start of journey and remove capacity[i] from end of journy then we find prefix sum and if at any point
            the sum is >capacity then we cannot fulfill the condition and return false else return true at the end.
*/
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>pick(2000);
        for(int i=0;i<trips.size();++i){
            pick[trips[i][1]]+=trips[i][0];
            pick[trips[i][2]]-=trips[i][0];
        }
        
        for(int i=0;i<1003;i++){
            if(i)pick[i]+=pick[i-1];
            if(pick[i]>capacity)return false;
        }
        return true;
    }
};
