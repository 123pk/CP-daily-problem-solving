/*
Platform :- Leetcode
Contest :- Leetcode Bi Weekly contest 67
Approach :- We will look for index which will be diffused if we diffuse any bomb , it will create  a disjoint set and answer is the maximum no of element in any Disjoint set
*/
class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int ans=0;
        int n=bombs.size();
        vector<vector<int>>graph(n);
        
        for(int i=0;i<bombs.size();++i){
            //cout<<" for "<<(i+1)<<"\n";
            int c=0;
            for(int j=0;j<bombs.size();++j){
                
                if(i==j)continue;
                
                long long temp = (bombs[j][0]-bombs[i][0]);
                long long temp2 = (bombs[j][1]-bombs[i][1]);
                temp*=temp;
                temp2*=temp2;
                
                long long temp3 = bombs[i][2];
                temp3*=temp3;
                
                temp+=temp2;
                //cout<<temp<<" "<<temp3<<"\n";
                if((temp-temp3)<=0){
                   // cout<<i<<" ** ";
                    graph[i].push_back(j);
                    //graph[j].push_back(i);
                }
                
            }
            //cout<<"\n";
            //ans=max(ans,c+1);
        }
         
        
        int c=0;
        ans=1;
        for(int i=0;i<n;++i){
             
            c=1;
             vector<int>vis(n);
            queue<int>bfs;
            bfs.push(i);
            vis[i]++;
            while(!bfs.empty()){
                int x = bfs.size();
                for(int j=0;j<x;++j){
                    int temp = bfs.front();
                    bfs.pop();
                    for(int k=0;k<graph[temp].size();++k){
                        if(vis[graph[temp][k]])continue;
                        
                        vis[graph[temp][k]]++;
                        bfs.push(graph[temp][k]);
                        c++;
                    }
                }
            }
            ans=max(ans,c);
        }
    
        return ans;
    }
};
