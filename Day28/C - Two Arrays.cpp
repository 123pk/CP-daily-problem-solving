/*
Platform :- Codeforces
Contest :- Codeforces Round 755 Div 2
Approach :- Just sort both the arrays if any element is not equal then if (B[i] - A[i] )!=1 the we cannot be able to make two array equal in one operation
*/
#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        int A[n];
        for(int i=0;i<n;++i){
            cin>>A[i];
        }
        
        map<int,int>P;
        vector<int>B(n);
        for(int i=0;i<n;++i){
            cin>>B[i];
            P[B[i]]++;
        }
        
        int f=0;
        
        sort(A,A+n);
        sort(B.begin(),B.end());
        for(int i=0;i<n;++i){
            if(A[i]!=B[i]){
                if((B[i]-A[i])==1)continue;
                f=1;
                break;
            }
        }
        
        
        if(f==0)cout<<"YES\n";
        else cout<<"NO\n";
        
        
    }
}
