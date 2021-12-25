/*
Platform :- Atcoder
Contest :- Atcoder Beginner Contet 233
Appraoch :- We do bfs and try to find those value which are divisor of remaning value.
*/
#include<bits/stdc++.h>
using namespace std;
 
int main(){
     int n;
     long long k;
     cin>>n>>k;
     
     int l;
     long long x;
     int ans=0,g=0;
     vector<pair<long long,long long>>P,temp;
     for(int i=0;i<n;++i){
         cin>>l;
         int f=0;
         map<long long,int>Q;
         for(int j=0;j<l;++j){
             cin>>x;
             Q[x]++;
         }
         
         if(i==0){
             for(auto &y:Q){
                 if(k%y.first==0){
                     f=1;
                     P.push_back({k/y.first,y.second});
                 }
             }
             if(f==0){
                 g=1;
             }
         }
         else{
              
                 for(int j=0;j<P.size();++j){
                     pair<long long,int> z = P[j];
                      
                     for(auto &y:Q){
                         if(z.first%y.first==0){
                             temp.push_back({z.first/y.first,z.second*y.second});
                             f=1;
                             if(i==n-1){
                                 if((z.first/y.first)==1)ans+=z.second*y.second;
                             }
                         }
                     }
                }
                P.clear();
                P=temp;
                temp.clear();
                
             if(f==0){
                 g=1;
             }
         }
          
        
     }
     if(g)ans=0;
     
     cout<<ans<<"\n";
}
