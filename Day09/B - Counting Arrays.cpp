/*
Platform :- Atcoder
Contest :- Atcoder Beginner Contest 226
Approach :- Simply use set of vector and print the size of the set
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
     int n;
     cin>>n;
     
     set<string>unq;
     string s;
     int d=0;
     long long x;
     for(int i=0;i<n;++i){
         int l;
         cin>>l;
         s="";
         for(int j=0;j<l;++j){
             cin>>x;
             s+=to_string(x);
             s+=',';
         }
          unq.insert(s);
     }
     cout<<(unq.size()+d)<<"\n";
}
