/*
Platform :- Codeforces
Contest :- Codeforces Global Round 18
Approach :- Find the sum of all values of the array and if the sum%n then we have 1 else we got 0
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
        long long tot=0;
        for(int i=0;i<n;++i){
            cin>>A[i];
            tot+=A[i];
        }
        
        long long val=tot/n;
        if(tot%n)cout<<1<<"\n";
        else cout<<0<<"\n";
        
    }
}
