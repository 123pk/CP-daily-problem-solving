/*
Platform :- Codechef
Contest :- Codechef Snackdown Round 1B
Approach :- It is only possible either all elements are equal of the differe between max and min element is 1.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int z;
        cin>>z;
        int n=1<<z;
        
        long long A[n];
        for(int i=0;i<n;++i){
            cin>>A[i];
        }
        
        sort(A,A+n);
        if(A[0]==A[n-1])cout<<"YES\n";
        else{
            if((A[n-1]-A[0])==1)cout<<"YES\n";
            else cout<<"NO\n";
        }
        
    }
}
