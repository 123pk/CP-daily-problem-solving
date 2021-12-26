/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 273
Approach :- If the last digit is non zero then we will get the same number else we will get something else.
*/
class Solution {
public:
    bool isSameAfterReversals(int num) {
        if(num==0)return 1;
        return num%10;
    }
};
