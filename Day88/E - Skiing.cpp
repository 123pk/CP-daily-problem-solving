/*
Platform :- Atcoder
Contest :- Atcoder Beginner Contest 237
Approach :- We will look for the maximum spanning tree or maximum value of happines if we visit all other nodes form node '1'.
            We just print the max of all such values.
*/
#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int>&P,pair<int,int>&Q){
    if(P.first==Q.first)return P.second<Q.second;
    return P.first<Q.first;
}

int main(){
     int n,m;
     cin>>n>>m;
     
     vector<int>h(n);
     for(int i=0;i<n;++i)cin>>h[i];
     
     int u,v;
     vector<int>graph[n];
     for(int i=0;i<m;++i){
         cin>>u>>v;
         u--;
         v--;
         graph[v].push_back(u);
         graph[u].push_back(v);
     }
     
     //MST maximum spanning tree
     queue<pair<int,long long>>bfs;
     bfs.push({0,0});
     vector<long long>val(n,-1e18);
     val[0]=0;
     
     while(!bfs.empty()){
         int c =bfs.size();
         for(int i=0;i<c;++i){
             pair<int,long long>temp = bfs.front();
             bfs.pop();
             int node = temp.first;
             long long cost = temp.second;
             for(auto &x:graph[node]){
                 long long y = cost;
                 if((h[node]>=h[x]))y+=(h[node]-h[x]);
                 else y+=(h[node]-h[x])*2ll;
                 
                 if(val[x]<y){
                     val[x]=y;
                     bfs.push({x,y});
                 }
             }
         }
     }
     
     long long ans=0;
     for(int i=1;i<n;++i)ans=max(ans,val[i]);
     cout<<ans<<"\n";
     
}
