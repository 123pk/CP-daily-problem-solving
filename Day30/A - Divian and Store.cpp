/*
Platform :- Codeforces
Contest :- Codeforces Round 757 Div 2
Approach :- Bruteforce it , sort the chocolates and chooose the chocolates which are not too cheap and neither too expensive and if you have the money to buy them then buy it.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        long long l,r,k;
        cin>>n>>l>>r>>k;
        
        long long A[n];
        for(int i=0;i<n;++i){
            cin>>A[i];
        }
        
        sort(A,A+n);
        int ans=0;
        //now choos those chocolates which are >=l && <=r
        for(int i=0;i<n;++i){
            if(l<=A[i] && A[i]<=r){
                if(k>=A[i]){
                    k-=A[i];
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
}
