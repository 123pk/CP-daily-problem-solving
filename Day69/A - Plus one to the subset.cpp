/*
Platform :- Codeforces
Contest :- Codeforces Round 764 Div 3
Approach :- Since we can only increment hence we nee to covert all value to the largest value and max no of operation required is [max_elemetn - min_element ] 
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
        sort(A,A+n);
        long long ans=0;
        ans=A[n-1]-A[0];
        cout<<ans<<"\n";
    }
}
