/*
Platform :- Leetcode
Approach :- We just need to determine if there is any cycle present or not , this is all about finding cycle in undirected graph
*/
class Solution {
public:
    
    void dfs(vector<vector<int>>&graph,int node,int &f,vector<int>&vis){
        vis[node]=1;
        
        for(auto&x : graph[node]){
            if(vis[x]==1){
                f=1;
                return;
            }
            else if(vis[x]==0)dfs(graph,x,f,vis);
        }
        vis[node]=2;
    }
    
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        //the basic approach is to look for cycle in differrent component
        // of graph
        vector<vector<int>>graph(n);
        for(auto &x:prerequisites){
            graph[x[1]].push_back(x[0]);
        }
        
        //now we will check for cycles in it
        
        vector<int>vis(n);
        for(int i=0;i<n;++i){
            if(vis[i])continue;
            
            int f=0;
            dfs(graph,i,f,vis);
            if(f)return false;
        }
        return true;
    }
};
