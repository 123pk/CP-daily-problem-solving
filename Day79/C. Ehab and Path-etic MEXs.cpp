/*
Platform :- Codeforces
Contest :- Codeforces Round 628 Div 2
Approach :- If you will carefully analyse the problem you will find that if 
            i .( max_degree_node  < 3 )  then we cannot do anything because we have linear tree , and we will assign value from 0 to n-2 in any order
            ii. we will get any node with ( degree >= 3 ) and assign all the edges from it value from (0 to x  , x=no of edges from this node) and randomly assign values to remmaining edges
                here the max MEX will not be >2 .
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
     
    vector<int>graph[n];
    vector<pair<int,int>>edges;
    map<pair<int,int>,int>weight;
    int u,v;
    int f=0,node;
    
    vector<int>degree(n);
    for(int i=0;i<n-1;++i){
        cin>>u>>v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u]++;
        degree[v]++;
        if(degree[u]==3){
            f=1;
            node=u;
        }
        
        if(degree[v]==3){
            node=v;
            f=1;
        }
        edges.push_back({min(u,v),max(u,v)});
    }
    
    if(f){
        int d=0;
        set<pair<int,int>>used;
        for(auto &x:graph[node]){
            used.insert({min(node,x),max(node,x)});
            weight[{min(node,x),max(node,x)}]=d;
            d++;
        }
        
        for(auto &x:edges){
            if(used.find(x)==used.end()){
                cout<<d<<"\n";
                d++;
            }
            else{
                cout<<weight[x]<<"\n";
            }
        }
        
    }
    else{
        for(int i=0;i<n-1;++i){
            cout<<i<<"\n";
        }
    }
    
    
    
}
