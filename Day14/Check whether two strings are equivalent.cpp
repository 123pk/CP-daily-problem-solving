/*
Platform :- Leetcode
Contest :- Leetcode bi weekly contest 65
Approach :- maintain frequency array for all alphabets of two string and check if the condition is broken or not.
*/
class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int>A(26),B(26);
        for(auto &x:word1)A[x-'a']++;
        
        for(auto &x:word2)B[x-'a']++;
        
        for(int i=0;i<26;++i){
            if(abs(A[i]-B[i])>3)return false;
        }
        return true;
    }
};
