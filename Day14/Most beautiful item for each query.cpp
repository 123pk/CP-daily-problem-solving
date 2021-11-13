/*
Platform :- Leetcode
Contest :- Leetcode Bi weekly contest 65
Approach :- Use binary search on the price and find the max value.
*/
bool comp(vector<int>&P,vector<int>&Q){
    if(P[0]==Q[0])return P[1]>Q[1];
    return P[0]<Q[0];
}

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        set<int>P;
        map<int,int>Q;
        for(auto &x:items)P.insert(x[0]);
        
        sort(items.begin(),items.end(),comp);
        vector<int>ans;
        int last=0;
        for(int i=0;i< items.size();++i){
            Q[items[i][0]]=max(last,items[i][1]);
            last=Q[items[i][0]];
            //cout<<(items[i][0])<<"--> "<<Q[items[i][0]]<<"\n";
        }
        
        for(int i=0;i<queries.size();++i){
            auto it=P.lower_bound(queries[i]);
            
            if(it==P.begin()){
                if((*it)>queries[i])ans.push_back(0);
                else ans.push_back(Q[(*it)]);
                continue;
            }
            if(it==P.end() || ((*it)>queries[i]))it--;
            //cout<<(*it)<<" check \n";
             ans.push_back(Q[(*it)]);
        }
        return ans;
    }
};
