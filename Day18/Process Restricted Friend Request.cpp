/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 267
Approach :- Bruteforce + Union find 
*/
class UnionFind {
    vector<int> id;
public:
    UnionFind(int n) : id(n) {
        iota(begin(id), end(id), 0);
    }
    void connect(int a, int b) {
        id[find(a)] = find(b);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    int connected(int a, int b) {
        return find(a) == find(b);
    }
};
class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& bans, vector<vector<int>>& requests) {
        vector<bool> ans;
        UnionFind uf(n);
        for (auto &r : requests) {
            int p = uf.find(r[0]), q = uf.find(r[1]); // the leaders of the two parties
            bool valid = true;
            if (!uf.connected(p, q)) { // Only need to check the bans if the two parties are not already connected
                for (auto &b : bans) {
                    int x = uf.find(b[0]), y = uf.find(b[1]); // the leaders of the two banned parties
                    if ((x == p && y == q) || (x == q && y == p)) {
                        valid = false;
                        break;
                    }
                }
            }
            ans.push_back(valid);
            if (valid) uf.connect(p, q); // connect two parties if request is valid
        }
        return ans;
    }
};
