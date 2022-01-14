/*
Platform :- Leetcode
Approach :- Using stringstream builtin library of c++
*/
class Solution {
public:
    int myAtoi(string s) {
        stringstream sam(s);
        int x=0;
        sam>>x;
        return x;
    }
};
