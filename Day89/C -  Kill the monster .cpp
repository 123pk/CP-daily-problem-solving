/*
Platform :- Codeforces
Contest :- Codeforces Educational Round 122
Approach :- Find greedily the most efficient way to use 'k' coins , start by using all 'k' coins in helath, then 'k-1'in health and '1' in attack and so on till '0' in health and 
          'k' in attack and if in any state we can beat the monster we print "YES"
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
         long long ch,ca,mh,ma;
         cin>>ch>>ca>>mh>>ma;
         
         long long k,a,h;
         cin>>k>>a>>h;
         
         /*
         The maximum upgrade I can do in order to win
         */
        long long health = ch,attack = ca;
        int f=0;
        
        health+=(k*h);
        
        long long c1 = 0,c2=0;
         //go for it greedily
         for(int i=0;i<=k;++i){
             
             c1 = mh/attack;
             if(mh%attack)c1++;
             
             c2 = health/ma;
             if(health%ma)c2++;
             
             if(c1<=c2){
                 f=1;break;
             }
             
             
             health-=h;
             attack+=a;
         }
         
         if(f)cout<<"YES\n";
         else cout<<"NO\n";
        
    }
}
