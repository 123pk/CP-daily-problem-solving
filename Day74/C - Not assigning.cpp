/*
Platform :- Codeforces
Contest :- Codeforces Round 766
Approach :- We have only valid solutiono when we have a linear tree with maximum degree 2 and only two nodes with degree 1 , here we choose any of the end and start assining 
             value '2' and '5' alternatively . 
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        int f=0;
        vector<int>tree[n];
        vector<int>degree(n);
        vector<pair<int,int>>edges;
        map<pair<int,int>,int>weight;
        for(int i=1;i<n;++i){
            int u,v;
            cin>>u>>v;
            v--;
            u--;
            edges.push_back({min(u,v),max(u,v)});
            
            tree[u].push_back(v);
            tree[v].push_back(u);
            degree[u]++;
            degree[v]++;
            if(degree[u]>2){
                f=1;
            }
        }
        
        if(f)cout<<"-1\n";
        else{
            queue<pair<int,int>>bfs;
            int d=0,idx;
            vector<int>used(n),ans(n);
            for(int i=0;i<n;++i){
                if(degree[i]==1){
                   idx=i;
                   d++;
                    
                }
            }
            
            if(d!=2){
                cout<<"-1\n";
                continue;
            }
            
            bfs.push({idx,0});
            used[idx]=1;
            while(!bfs.empty()){
                int c=bfs.size();
                for(int i=1;i<=c;++i){
                    pair<int,int>temp = bfs.front();
                    bfs.pop();
                    int node=temp.first;
                    int val=temp.second;
                   
                    
                    for(auto &x:tree[node]){
                        if(used[x]){
                            continue;
                        }
                        used[x]=1;
                         
                        if(val==0){
                            weight[{min(node,x),max(node,x)}]=2;
                            bfs.push({x,1});
                        }
                        else{
                            weight[{min(node,x),max(node,x)}]=5;
                            bfs.push({x,0});
                        }
                        
                         
                        
                    }
                }
            }
            
            for(auto &x:edges){
                cout<<weight[x]<<" ";
            }
            cout<<"\n";
        }
    }
}
