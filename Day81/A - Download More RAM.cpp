/*
Platform :- Codeforces
Contest :- Codeforces Round 767 Div 2
Approach :-sort them on basis of the minimum requirement in increasing order.
*/
#include<bits/stdc++.h>
using namespace std;

bool comp(pair<long long,long long>&P,pair<long long,long long>&Q){
    if(P.first==Q.first)return P.second>Q.second;
    return P.first<Q.first;
}


int main(){
     int t;
     cin>>t;
     
     while(t--){
         int n;
         long long k;
         cin>>n>>k;
         
         vector<pair<long long,long long>>P;
         long long A[n],B[n];
         for(int i=0;i<n;++i)cin>>A[i];
         for(int j=0;j<n;++j){
             cin>>B[j];
             P.push_back({A[j],B[j]});
         }
         
         sort(P.begin(),P.end(),comp);
         
         long long ans=k;
         for(int i=0;i<n;++i){
             if(ans>=P[i].first)ans+=P[i].second;
         }
         
         cout<<ans<<"\n";
         
     }
    
}
