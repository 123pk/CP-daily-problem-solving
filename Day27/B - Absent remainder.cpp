/*
Platform :- Codeforces
Contest:- Codeforces Educational Round 118
Approach :- Make n/2 pair with smallest element as 'y'
*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
     int t;
     cin>>t;
     
     while(t--){
         int n;
         cin>>n;
         
         long long A[n];
         for(int i=0;i<n;++i){
             cin>>A[i];
         }
         sort(A,A+n);
         for(int i=1;i<=(n/2);++i){
             cout<<A[i]<<" "<<A[0]<<"\n";
         }
        // cout<<"\n";
     }
}
