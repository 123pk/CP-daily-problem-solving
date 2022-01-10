/*
Platform :- Codeforces
Contest :- Codeforces Round 764 Div 3
Approach :- First if there are element in array which are also in permutation leave them and mark them so that we will not change them, for rest of elements we divide by 2 and 
            if any unused elemment of permuataion is formed we mark it and if at the end all the elements are marked then we print yes else no
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
         int n;
         cin>>n;
         
         long long A[n];
         //map<long long,vector<long long>>P;
         set<int>unq;
         vector<int>used(n);
         for(int i=1;i<=n;++i)unq.insert(i);
         
         for(int i=0;i<n;++i){
             cin>>A[i];
             
             if(A[i]<=n){
                 if(unq.find(A[i])!=unq.end()){
                     unq.erase(A[i]);
                     used[i]++;
                 }
             }
             /*
             z=A[i];
             while(A[i]){
                 A[i]/=2;
                 P[A[i]]++;
             }*/
         }
         
         int f=0;
         for(int i=0;i<n;++i){
             
             if(used[i]){
                 continue;
             }
             
             while(A[i] && unq.size()){
                 A[i]/=2;
                 if(unq.find(A[i])!=unq.end()){
                     unq.erase(A[i]);
                     break;
                 }
             }
             
             /*if(P[i]==0){
                 f=1;break;
             }*/
         }
         
         if(unq.size())cout<<"NO\n";
         else cout<<"YES\n";
                 
    }
}
