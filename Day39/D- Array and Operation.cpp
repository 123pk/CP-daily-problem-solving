/*
Platform :- Codeforces
Contest :- Codeforces Round 760 Div 3
Approach :- Sort the array and since we need to minimise the sum , then we choose the last (n-(2*k)) elements as they contribute to the largest part of sum , we choose (n-2k,n-k),
           (n-2k+1,n-k+1)...and so on . This will help us in acheiving the desired sum.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
         
        
        int A[n];
    
        long long tot=0;
        
        for(int i=0;i<n;++i){
            cin>>A[i];
            tot+=A[i];
             
        }
        
        sort(A,A+n);
         
        int z=n-k;
        int start=z-k;
        int d=0;
        while(k--){
            
            int change = A[start]/A[z+d];
            
            tot-=((A[start]+A[z+d])-change);
            start++;
            d++;
        }
        
        cout<<tot<<"\n";
    }
}
