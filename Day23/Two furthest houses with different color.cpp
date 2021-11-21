/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 268
Approach :- The basic approach is the max distance between first element and last element no equal to first element or last element and first element that is not equal to last eleemnt.
*/
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans=0;
        for(int i=colors.size()-1;i>0;--i){
            if(colors[i]!=colors[0]){
                ans=i;break;
            }
        }
        
        for(int i=0;i<colors.size()-1;++i){
            if(colors[i]!=colors[colors.size()-1]){
                ans=max(ans,int(colors.size()-(i+1)));
                break;
            }
        }
        return ans;
    }
};
