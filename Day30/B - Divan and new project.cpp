/*
Platform :- Codeforces
Contest :- Codeforces Round 757 Div 2
Approach :- Sort the given values and we want to keep those buildings near to the office which we need to visit most number of times or we can say the relation between distance
            and the number of times we want to visit them are directly dependent. chhose any integer coordinate and set it to office now start making building either side of it 
            chhosing the most visited building to be the first.
*/
#include<bits/stdc++.h>
using namespace std;

bool comp(pair<long long,int>P,pair<long long,int>Q){
    if(P.first==Q.first)return P.second<Q.second;
    return P.first>Q.first;
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
         int n;
         cin>>n;
         
         long long x;
         vector<pair<long long,int>>P;
         for(int i=0;i<n;++i){
             cin>>x;
             P.push_back({x,i});
         }
         sort(P.begin(),P.end(),comp);
         
         //now let our rivian sit on 0
         long long tot=0;
         vector<int>pos(n+1);
         int d=0,e=0,f=0;
         pos[0]=0;
         int last_pos=0;
         d=1;
         long long curr_pos=0;
         
         for(int i=0;i<n;++i){
             
             if(f){
                 curr_pos-=d;
                 f=0;
                 
             }
             else{
                 curr_pos+=d;
                 f=1;
             }
             d++;
             
             long long ab = abs(last_pos-curr_pos);
             ab*=2;
             ab*=P[i].first;
            // cout<<ab<<" check ";
             tot+=(ab);
             
             pos[P[i].second+1]=curr_pos;
         }
         
         cout<<tot<<"\n";
         for(auto &x:pos)cout<<x<<" ";
         cout<<"\n";
    }
}
