/*
Platform :- Codeforces
Contest :- Codeforces Round 771 Div 2
Approach :- You need to carefully understand the problem and you will that if there odd elements of array or even elements of array when taken seperately are not sorted then
             we cannot sort else we can sort
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
         vector<long long>odd(n),even(n);
         for(int i=0;i<n;++i){
             cin>>A[i];
             if(A[i]%2)odd.push_back(A[i]);
             else even.push_back(A[i]);
         }
         
         int f =0 ;
         
         for(int i =1;i<odd.size();++i){
             if(odd[i]<odd[i-1]){
                 f=1;break;
             }
         }
         
         for(int i = 1;i<even.size(); ++i){
             if(even[i]<even[i-1]){
                 f=1;break;
             }
         }
         
         if(f)cout<<"No\n";
         else cout<<"Yes\n";
         
    }
}
