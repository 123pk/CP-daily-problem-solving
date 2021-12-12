/*
Platform :- Codeforces
Contest :- Codeforces Round 759 
Approach :- Here if the max element comest to the end then we start getting same sequence , so we will look for lenght of increasing subsequnce from behind and ans is len-1 .
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        long long mx=0;
        long long A[n];
        for(int i=0;i<n;++i){
            cin>>A[i];
            mx=max(mx,A[i]);
        }
        
        if(A[n-1]==mx)cout<<"0\n";
        else{
            long long prev=A[n-1];
            int ans=0;
            for(int i=n-1;i>=0;--i){
                if(A[i]>prev){
                    prev=A[i];
                    ans++;
                }
            }
            cout<<ans<<"\n";
        }
        
        
    }
}
