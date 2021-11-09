/*
Platform :- Leetcode
Approach :- 
*/
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<int> count(1<<26, 0);
        for (int i = 0; i < words.size(); i++) {
            int bit = 0;
            for (auto c: words[i]) {
                bit |= (1<<(c-'a'));
            }
            count[bit] ++;
        }
        vector<int> res;
        for (int i = 0; i < puzzles.size(); i++) {
            int cnt = 0;
            for (int j = 0; j < (1<<6); j++) {
                int bit = 1<<(puzzles[i][0]-'a');
                for (int k = 0; k < 6; k++) {
                    if ((j & (1<<k)) > 0) {
                        bit |= 1<<(puzzles[i][k+1]-'a');
                    }
                }
                cnt += count[bit];
            }
            res.push_back(cnt);
        }
        return res;
    }
};
