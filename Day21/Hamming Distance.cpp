/*
Platform :- Leetcode
Appraoch :- first convert the given number into 32 bit string representation and check for all the 32 bits that are not equal and count of those is our answer
*/
class Solution {
public:
    int hammingDistance(int x, int y) {
        string temp=bitset<32>(x).to_string();
        string temp2 = bitset<32>(y).to_string();
        
        int ans=0;
        for(int i=0;i<32;++i){
            if(temp[i]!=temp2[i])ans++;
        }
        return ans;
    }
};
