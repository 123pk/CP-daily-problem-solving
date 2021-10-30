/*
Platform :- Codeforces
Contest :- Codeforces Round 752 Div 2
Approach :- check if (i+ans)>=A[i] else ans += (A[i]-(i+ans)) this is for 1 based indexing .
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
        for(int i=0;i<n;++i){
            cin>>A[i];
        }
        
        long long ans=0;
        
        for(int i=0;i<n;++i){
           // cout<<A[i]<<" "<<ans<<" "<<i<<endl;
            if((A[i])<=(i+1+ans)){
                continue;
            }
            else{
                ans+=(A[i]-(i+1+ans));
            }
           // cout<<ans<<" ";
        }
        
        cout<<ans<<"\n";
        
    }
}
