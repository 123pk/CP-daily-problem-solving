/*
Platform :- Leetcode
Approach :- We do a binary search from  1 to max element of array and find the smallest values which satisfies our condition.
*/
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int speed=INT_MAX;
        long long s = 1,e=1,m=(s+e)/2;
        long long tm = 0;
        
        for(auto &x:piles){
            tm=x;
            e=max(e,tm);
        }
     
        tm=0;
        
        while(s<=e){
            
            tm=0;
            for(int i=0;i<piles.size();++i){
                tm+=(piles[i]/m);
                if(piles[i]%m)tm++;
            }
            
            if(tm<=h){
                speed=min(speed,int(m));
                e=m-1;
                m=(s+e)/2;
            }
            else{
                s=m+1;
                m=(s+e)/2;
            }
        }
        
        return speed;
    }
};
