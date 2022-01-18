/*
Platform :- Atcoder
Approach :- Dp problem with ,for finding minimum cost to reach ith step we either jump from (i-1) step or (i-2) step 
           dp[0]=A[0]
           dp[1]=abs(A[1]-A[0]) , dp[2]=min(abs(A[2]-A[0],dp[1]+abs(A[2]-A[1])
           else dp[i]=min(dp[i-1]+abs(A[i]-A[i-1]) , dp[i-2]+abs(A[i]-A[i-2])
*/
#include<bits/stdc++.h>
using  namespace std;

int main(){
    int n;
    cin>>n;
    
    long long A[n];
    long long dp[n];
    for(int i=0;i<n;++i){
        cin>>A[i];
    }
    
    dp[0]=A[0];
    dp[1]=abs(A[1]-A[0]),A[1];
    dp[2]=min(dp[1]+abs(A[2]-A[1]),abs(A[2]-A[0]));
    for(int i=3;i<n;++i){
        dp[i]=min(dp[i-1]+abs(A[i]-A[i-1]),dp[i-2]+abs(A[i]-A[i-2]));
    }
   // for(int i=0;i<n;++i)cout<<dp[i]<<" ";
    
    cout<<dp[n-1]<<"\n";
}
