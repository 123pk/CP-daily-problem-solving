/*
Platform :- Codeforces
Contest :- Codeforces Round 536 Div 2
Appraoch :- Do bfs using a min priority queue (  min heap) everytime we want to use the node with the smallest value out of all adjancent ones .
  
  */
#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&graph,int node,vector<int>&vis,vector<int>&ans){
    if(vis[node]==0){
        vis[node]++;
        ans.push_back(node);
      //  cout<<node+1<<' ';
    }
    
    //ans.push_back(node);
    
    for(auto &x:graph[node]){
        if(vis[x])continue;
        dfs(graph,x,vis,ans);
    }  
}

int main(){
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>>graph(n);
    int u,v;
    for(int i=0;i<m;++i){
        cin>>u>>v;
        u--;v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    for(int i=0;i<n;++i){
        sort(graph[i].begin(),graph[i].end());
    }
    
    vector<int>vis(n),ans;
    
    priority_queue<int,vector<int>,greater<int>>bfs;
    bfs.push(0);
    vis[0]++;
    while(!bfs.empty()){
        int c  = bfs.size();
        int temp  =bfs.top();
        bfs.pop();
         
        ans.push_back(temp);
        for(auto&x:graph[temp]){
            if(vis[x])continue;
            vis[x]++;
            bfs.push(x);
        }
    }
    
  //  dfs(graph,0,vis,ans);
    for(auto &x:ans)cout<<x+1<<" ";
    cout<<"\n";
}
