/*
Platform :- Atcoder
Approach :- Classic 0/1 knapsack problem
*/
#include<bits/stdc++.h>
using namespace std;
long long wt[101],cost[101];
long long dp[101][100001];

long long find(int idx,int wt_left){
    
    if(wt_left == 0)return 0;
    if(idx<0)return 0;
    
    if(dp[idx][wt_left]!=-1)return dp[idx][wt_left];
    
    long long ans = find(idx-1,wt_left);
    if(wt_left-wt[idx]>=0)ans = max(ans,find(idx-1,wt_left-wt[idx])+cost[idx]);
    
    return dp[idx][wt_left] = ans;
}

int main(){
    
    memset(dp,-1,sizeof(dp));
    long long n,w;
    cin>>n>>w;
    
     
    for(int i=0;i<n;++i)cin>>wt[i]>>cost[i];
    
    cout<<find(n-1,w)<<"\n";
    
}
