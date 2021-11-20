/*
Platform :- Codeforces
Contest :- Codeforces Round 747 Div 2
Approach :- Try to color the graph with two colors and if there is any contradictions that occurs which doesnot satisfy the arrangment of nodes then print -1 else print 
             the max no of colors of any type in all the disjoint set or explicit graphs.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,m;
        cin>>n>>m;
        
        int u,v;
        string s;
        vector<vector<pair<int,int>>>graph(n);
        for(int i=0;i<m;++i){
            cin>>u>>v>>s;
            v--;u--;
            if(s=="imposter"){
                //type one means different color between nodes of edges both nodes can't have same color
                graph[u].push_back({v,1});
                graph[v].push_back({u,1});
            }
            else{
                graph[u].push_back({v,2});
                graph[v].push_back({u,2});
            }
        }
        
        //now we will carefully assing some color starting with 1 and 
        // if at some point we contradict then we print -1
        vector<int>parent(n,-1),vis(n);
        int c=0,d=0,f=0,ans=0;
        for(int i=0;i<n;++i){
            if(parent[i]==-1){
                c=0,d=0;
                parent[i]=1;
                queue<int>bfs;
                bfs.push(i);
                while(!bfs.empty()){
                    int temp = bfs.front();
                    if(parent[temp]==1)c++;
                    else d++;
                    bfs.pop();
                    for(auto &x:graph[temp]){
                        int val = x.first;
                        int type = x.second;
                        
                        //I have already visited this node
                        if(parent[val]!=-1){
                            if(type==1 && parent[temp]==parent[val])f=1;
                            if(type==2 && parent[temp]!=parent[val])f=1;
                            continue;
                        }
                        else{
                            if(type==1){
                                parent[val]=3-parent[temp];
                            }
                            else{
                                parent[val]=parent[temp];
                            }
                            bfs.push(val);
                        }
                    }
                    if(f)break;
                }
                if(f)break;
                ans+=max(c,d);
            }
        }
        
        for(int i=0;i<n;++i){
            if(parent[i]==1)c++;
            else d++;
        }
         
        
        
        if(f)cout<<"-1\n";
        else cout<<ans<<"\n";
    }
}
