/*
Platform :- Codeforces
Contest :- Codeforces Educational Round 119

*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
         int n,m;
         cin>>n>>m;
         
         vector<int>x1,x2,y1,y2;
         int k,a;
         cin>>k;
         
         for(int i=0;i<k;++i){
             cin>>a;
             x1.push_back(a);
         }
         cin>>k;
         for(int i=0;i<k;++i){
             cin>>a;
             x2.push_back(a);
         }
         
         cin>>k;
         
         for(int i=0;i<k;++i){
             cin>>a;
             y1.push_back(a);
         }
         cin>>k;
         for(int i=0;i<k;++i){
             cin>>a;
             y2.push_back(a);
         }
         
          
         long long ans=0;
         
         //for y == 0 
         long long a1 = x1[x1.size()-1]-x1[0];
         a1*=m;
         ans=a1;
         
         
         //for y == m
         a1 = x2[x2.size()-1]-x2[0];
         a1*=m;
         ans=max(ans,a1);
         
         
         //for x == 0
         a1 = y1[y1.size()-1]-y1[0];
         a1*=n;
         ans=max(ans,a1);
         
         
         // for x == n
         a1 = y2[y2.size()-1]-y2[0];
         a1*=n;
         ans=max(ans,a1);
          
         
         cout<<ans<<"\n";
    }
}
