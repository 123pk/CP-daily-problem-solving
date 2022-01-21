/*
Platform :- Leetcode
Approach :- We start from first gas startation and assume it to be the starting point , if at any point we are out of fuel and not able to make till the next station then we
            just move our start station a bit backward which in our case will be last station as they are in cycle , we do this until we found 1 , if there are no station then 
            return -1;
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int idx=-1;
        
        //which gas station to choose
        int start=0,d=0,n=gas.size();
        int tot=0;
        for(int i=0;i<n-d;++i){
            tot+=(gas[i]-cost[i]);
            if(tot<0){
                while(tot<0 && d<n){
                    tot+=(gas[n-1-d]-cost[n-1-d]);
                    start=n-1-d;
                    d++;
                }
                
                if(tot<0)return -1;
            }
        }
        
        return start;
    }
};
