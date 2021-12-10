/*
Platform :- Leetcode
Approach :- We will do dfs from start and maintain a visited array so that we donot visit any node multiple times , and for each index we will look for "left" and "right" index 
            we can reach from current index and do dfs on them.
*/
class Solution {
public:
    
    void check(vector<int>&A,int idx , vector<int>&vis , int& f){
        vis[idx]++;
        
        if(A[idx]==0){
            f=1;
            return;
        }
        int right = idx + A[idx];
        int left = idx - A[idx];
        
        if(right<A.size() && vis[right]==0){
            check(A,right,vis,f);
        }
        
        if(left>=0 && vis[left]==0){
            check(A,left,vis,f);
        }
        
    }
    
    bool canReach(vector<int>& A, int start) {
         //check for circle 
        int f = 0;
        int n = A.size();
        vector<int>vis(n);
        check(A,start,vis,f);
        return f==1;
    }
};
