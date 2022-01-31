/*
Platform:- Codeforces
Contest :- Codeforces Round 635
Approach :- We sort the nodes by increasing value of (depth [u] - no_of_nodes_in_subtree[u])
*/
#include<bits/stdc++.h>
using namespace std;
#define  int long long

int dfs(vector<vector<int>>&graph,int node,vector<int>&sub,vector<int>&vis){
    
    if(vis[node]==0){
        sub[node]++;
        vis[node]++;
    }
    
    for(auto &x:graph[node]){
        if(vis[x])continue;
        sub[node]+=dfs(graph,x,sub,vis);
    }
    return sub[node];
}

int32_t main(){
    int n,k;
    cin>>n>>k;
    
    int u,v;
    vector<vector<int>>graph(n);
    for(int i=1;i<n;++i){
        cin>>u>>v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    /*
    We want to get the level and 
    */
    vector<int>dep(n),sub(n);
    vector<int>vis(n);
    dfs(graph,0,sub,vis);
    
    queue<pair<int,int>>bfs;
    bfs.push({0,0});
    vector<int>used(n);
    used[0]=1;
    
    while(!bfs.empty()){
        int c = bfs.size();
        for(int i=0;i<c;++i){
            pair<int,int>temp = bfs.front();
            bfs.pop();
            int  node = temp.first;
            int d = temp.second;
            dep[node] = d;
            for(auto &x:graph[node]){
                if(used[x])continue;
                used[x]++;
                bfs.push({x,d+1});
            }
        }
    }
    
    vector<int>final;
    for(int i=0;i<n;++i){
        final.push_back((dep[i]+1)-sub[i]);
    }
    int ans = 0;
    sort(final.begin(),final.end(),greater<int>());
    for(int i=0;i<k;++i)ans+=final[i];
    cout<<ans<<"\n";
}
