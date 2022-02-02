/*
Platform :- Codechef
Contest :- Codechef Starters ( 2 feb 2022 ) 
Approach :- We should know that [ f(n) = sum of reciprocal of divisors of any number 'n'  ] so "sum of divisors 'X' = n*f(n) 
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
         long long x,a,b;
         cin>>x>>a>>b;
         
         long long val = (b*x);
         
         if(a==1 && b==1){
             if(x!=1)cout<<"-1\n";
             else cout<<1<<"\n";
             continue;
         }
         
         if(val%a)cout<<"-1\n";
         else{
             val/=a;
             if(x<=val)cout<<"-1\n";
             else cout<<val<<"\n";
         } 
          
    }
}
