/*
Platform :- Atcoder
Contest :- Atcoder Contest 226
Approach :- We do bfs from all the values required for nth skill and do maintain an used where where we store the skill required and add that time taken at the end to our answer
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
     int n;
     cin>>n;
    
    vector<long long>T(n);
    int k;
    int x;
    vector<int>P[n];
    vector<int>used(n);
    int mn,mx;
    for(int i=0;i<n;++i){
        cin>>T[i]>>k;
        for(int j=0;j<k;++j){
           cin>>x;
           P[i].push_back(x-1);
        }
    }
    
    //now do bfs in rervse order
    queue<int>bfs;
    used[n-1]++;
    for(int i=0;i<P[n-1].size();++i){
        used[P[n-1][i]]++;
        bfs.push(P[n-1][i]);
    }
    
    while(!bfs.empty()){
        int c=bfs.size();
        for(int i=0;i<c;++i){
            int temp = bfs.front();
            bfs.pop();
            for(int j=0;j<P[temp].size();++j){
                if(used[P[temp][j]]==0){
                    used[P[temp][j]]++;
                    bfs.push(P[temp][j]);
                }
            }
        }
    }
    long long ans=0;
    for(int i=0;i<n;++i){
        if(used[i])ans+=T[i];
    }
    cout<<ans<<"\n";
}
