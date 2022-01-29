/*
Platform :- Leetcode
Approach :- We will use same like dijkstara algorith and we will store the max weighted path ( contining probability) in this condition and use max heap in place of min heap 
            to have max probability of path from start to all the other nodes
*/
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& wt, int start, int end) { 
         
        double ans = 0;
        vector<int>graph[n];
        for(int i=0;i<edges.size();++i){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        map<pair<int,int>,double>weight;
        for(int i=0;i<edges.size();++i){
            weight[{min(edges[i][0],edges[i][1]),max(edges[i][0],edges[i][1])}] = wt[i];
        }
        
        vector<double>prob(n,0.0);
        prob[start] = 1.0;
        priority_queue<pair<double,int>>djk;
        djk.push({1.0,start});
        
        while(!djk.empty()){
            pair<double,int> temp = djk.top();
            djk.pop();
            double val = temp.first;
            int node = temp.second;
            
         //   cout<<node<<" "<<val<<"--\n";
            
            for(auto &x:graph[node]){
                double y = val*weight[{min(node,x),max(node,x)}];
               
          //      cout<<x<<" "<<y<<"\n";
               
                if(y>prob[x]){
                    prob[x] = y;
                    djk.push({y,x});
                }
            }
        }
        
        return prob[end];
    }
};
