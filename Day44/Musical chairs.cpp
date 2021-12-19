/*
Platform :- Codechef
Contest :- Codeforces Cook off December 2021
Approach :- After the contest 
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
   int t;
   cin>>t;
   
   while(t--){
       long long n;
       cin>>n;
       n--;
       
       long long ans=0;
       for(long long i=1;i*i<=n;++i){
           if(n%i==0){
               if(n/i==i){
                   ans++;
               }
               else ans+=2;
           }
       }
       cout<<ans<<"\n";
   }
}
