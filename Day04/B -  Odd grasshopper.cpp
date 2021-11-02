/*
Platform :- Codeforces
Contest :- Codeforces Round 753 Div 3
Approach :- If you will analyse carefully you will find that after every 4 itteration you came back to same place where you started from so all problem comes down to itterating
            (n % 4) times from ith ..to nth values .
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
         long long x,n;
         cin>>x>>n;
         
         long long z=n%4;
         long long ans=x;
         long long k=(n-z)+1;
         while(z--){
             if(ans%2){
                 ans+=k;
             }
             else ans-=k;
             k++;
         }
         
         cout<<ans<<"\n";
    }
}
