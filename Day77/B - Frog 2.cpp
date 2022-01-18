
/*
Platform :- Atcoder
Approach :- Dp problem with ,for finding minimum cost to reach ith step we either jump from (i-1) step or (i-2) step or ... (i-k) steps and min of all is choosen
           dp[0]=A[0]
            
*/
#include<bits/stdc++.h>
using  namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    
    long long A[n];
    long long dp[n];
    for(int i=0;i<n;++i){
        cin>>A[i];
    }
    
    dp[0]=A[0];
    dp[1]=abs(A[1]-A[0]);
    for(int i=2;i<n;++i){
        dp[i]=dp[i-1]+abs(A[i]-A[i-1]);
        for(int j=1;j<=k && (i-j)>=0;++j){
            if(i==j)dp[i]=min(dp[i],abs(A[i]-A[i-j]));
            else dp[i]=min(dp[i-j]+abs(A[i]-A[i-j]),dp[i]);
        }
    }
   //  for(int i=0;i<n;++i)cout<<dp[i]<<" ";
    
    cout<<dp[n-1]<<"\n";
}
