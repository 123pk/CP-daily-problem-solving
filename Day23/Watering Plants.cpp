/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 268
Approach :- We will use bruteforce approach where we will fill our can with full capacity and water the plants if the amoount of water in can is less than the water plant require
            then we will go back to river and continue the process.
*/
class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int ans=0,d=capacity;
        
        for(int i=0;i<plants.size();++i){
            if(d<plants[i]){
                d=capacity;
                ans+=(2*i)+1;
                d-=plants[i];
            }
            else{
                d-=plants[i];
                ans++;
            }
        }
        
        
        return ans;
    }
};
