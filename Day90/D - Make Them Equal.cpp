/*
Platform :- Codeforces
Contest :- Educational Round 122
Approach :- First precalculate the min cost of making value 'i' from '1' , now we change each of the value in input with their min cost and now the problem is turned down to 
            dp 01 knap sack and to avoid MLE (Memory limit exceeded ) find the sum of all the elemets cost in input and if the ( k > sum_min_operations) then simply our answer is (sum_of_cost)
*/
#include<bits/stdc++.h>
using namespace std;

 
/*
Approach is to find min cost to reach all the values from 1 to 1000 as the lim our values is 1000
then the problem comes down to knapsack with k and max values we can acheive
*/

int main(){
    int t;
    cin>>t;
    
  //  queue<int>bfs;
    vector<int>val(1001);
    for(int i=0;i<=1000;++i)val[i]=INT_MAX;
  //  bfs.push({2,1});
    val[0] = 0;
    val[1] = 0;
    val[2] = 1;
     int x;
 //   vector<int>fact;
    for(int i=2;i<=1000;++i){
        //find the factors
      //  fact.clear();
        for(int j=1;j<=i;++j){
            x = i+(i/j);
            if(x>1000)continue;
            val[x] = min(val[x],val[i]+1);
        }
    }
    
   // for(int i=1;i<=20;++i){
   //     cout<<i<<" with cost "<<val[i]<<"\n";
   // }
    
    while(t--){
        int n,k;
        cin>>n>>k;
        
        vector<int>A(n);
        int tot = 0;
        for(int i=0;i<n;++i){
            cin>>A[i];
            A[i] = val[A[i]];
            tot+=A[i];
        }
        
        vector<int>wt(n);
        int cost = 0;
        for(int i=0;i<n;++i){
            cin>>wt[i];
            cost+=wt[i];
        }
        
        if(tot<=k){
            cout<<cost<<"\n";
            continue;
        }
        
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        
        for (int i=0; i<n; ++i) {
        for (int j=0; j<=k; ++j) {
            if (j>=A[i]) {
                dp[i+1][j] = max(dp[i+1][j], dp[i][j-A[i]]+wt[i]);
            }
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
          }
        }
        
        cout<<dp[n][k]<<"\n";
    }
}
