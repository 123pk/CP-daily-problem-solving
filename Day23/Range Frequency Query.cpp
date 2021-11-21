/*
Platform : Leetcode
Contest :- Leetcode Weekly contest 268
Approach :- We need to store the index for each value and do binary search on them to find the amount of such values .
*/

class RangeFreqQuery {
public:
   
    vector<vector<int>>P;
    unordered_map<int,int>T;
    set<int>zz;
    vector<int>S,Q;
    //unordered_map<int,int>Q;
    //Q stores the frequenct of element at that index
    RangeFreqQuery(vector<int>& arr) {
        
        int d=1,n=arr.size();
        
        for(int i=0;i<arr.size();++i){
           zz.insert(arr[i]);
        }
        d=zz.size();
        S.resize(d);
        Q.resize(n);
        P.resize(d);
        d=0;
        for(auto &x:zz){
            T[x]=d;
            d++;
        }
        
        for(int i=0;i<arr.size();++i){
            d = T[arr[i]];
            P[d].push_back(i);
            S[d]++;
            Q[i]=S[d];
        }
        
    }
    int x;
    
    int query(int left, int right, int value) {
        int ans=0;
         
        
        if(zz.find(value)==zz.end())return 0;
         
        x=T[value];
        auto it = lower_bound(P[x].begin(),P[x].end(),left);
        if(it==P[x].end()){
            return 0;
        }
        auto it2 = lower_bound(P[x].begin(),P[x].end(),right);
        if(it2==P[x].end() || (*it2)>right){
            if(it2==P[x].begin())return 0;
            else it2--;
        }
        
        if((*it2)<(*it))return 0;
         
        ans=Q[(*it2)]-Q[(*it)]+1;
         
        
        return ans;
        
         

    }
};
 
