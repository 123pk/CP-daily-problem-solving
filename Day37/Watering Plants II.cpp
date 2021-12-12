/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 271
Approach :- Use two pointers one from start and one from end and start watering plants if the can has less water than required then fill the can and update answer and continue.
*/
class Solution {
public:
    int minimumRefill(vector<int>& plants, int cap1, int cap2) {
        int ans=0;
        int a=cap1,b=cap2;
        int i=0,j=plants.size()-1;
        while(i<=j){
            if(i==j){
                if(max(a,b)<plants[i]){
                    ans++; 
                }
            }
            else{
                if(a<plants[i]){
                   a=cap1;
                   a-=plants[i];
                   
                    ans++;
                }
                else{
                    a-=plants[i];
                    
                }
                
                if(b<plants[j]){
                    b=cap2;
                    b-=plants[j];
                    ans++;
                }
                else{
                    b-=plants[j];
                }
            }
            i++;
            j--;
        }
        
        return ans;
    }
};
