/*
Platform :- Codeforces
Contest :- Codeforces Round 498
Approach :- First find the no of nodes in subtree for each node of tree then for each node calculate the no of vlaues till ith node , key idea for answering querie is,
            we will check if there are enough nodes in subtree to trasfer message or not if there are enough nodes then we will try to find the (no_of_nodes_till_u + k ) from root
            will give the answer . So we store the distance of each node from root that will help us in getting the solution to each query in O(1)
*/
#include<bits/stdc++.h>
using namespace std;
 
//function to find the no of nodes in subtree of each node , distance of each node from root and ith node from root
int find(vector<vector<int>>&graph,int node,vector<int>&values,vector<int>&vis,vector<int>&till,vector<int>&that,int&tot){
    
    if(vis[node]==0){
        vis[node]++;
        till[node]=tot;
        tot++;
        that[tot]=node;
    }
    if(graph[node].size()==0){
        values[node]=1;
        return 1;
    }
    
    for(auto &x:graph[node]){
        values[node]+=find(graph,x,values,vis,till,that,tot);
    }
    values[node]+=1;
    return values[node];
}

 

int main(){
    int n,q;
    cin>>n>>q;
    
    int x;
    vector<int>parent(n);
    parent[0]=0;
    vector<vector<int>>graph(n);
    for(int i=1;i<n;++i){
        cin>>x;
        x--;
        parent[i]=x;
        graph[x].push_back(i);
    }
    
    //ordering graph based on the values
    for(int i=0;i<n;++i){
        sort(graph[i].begin(),graph[i].end());
    }
    
    vector<int>values(n),vis(n);
    int tot=0;
    vector<int>till(n),that(n+1);
    tot = find(graph,0,values,vis,till,that,tot);
  
   
  
   
    int u,k;
    for(int i=0;i<q;++i){
        
        cin>>u>>k;
        u--;
        //cout<<1<<"\n";
        if(values[u]<k){
            cout<<"-1\n";
            continue;
        }
        int z = till[u]+k;
        cout<<(that[z]+1)<<"\n";
    }
}
