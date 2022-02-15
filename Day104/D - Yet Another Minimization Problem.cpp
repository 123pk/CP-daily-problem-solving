/*
Platform :- Codeforces
Contest :- Codeforces Global Round 19
Approach :- Since the sum of the two array remains constant of the values we swap , We need to simplify the equation to [ (n-2)*(sum_of_squares_of_all_values) + sum_of_A^2 + sum_of_B^2 ] 
            so we need to minimise the [sum_of_A^2 + sum_of_B^2 ] , So we will use bool array to check if we can get to the value betwee [1 to m*n ] and find 
            min of (i^2 + (m*n-i)^2 )
*/
#include<bits/stdc++.h>
using namespace std;

//long long dp[101][10001];
//int A[101],B[101];

 /*
 YOU NEED TO REDUCE THE EXPRESSION 
 N-2 * sUM OF (a[I]^2 +  B[I]^2)  + (SUM_OF_a)^2 + sum-of_b^2
 */

int main(){
    
    int t;
    cin>>t;
    
    while(t--){
        //memset(dp,-1,sizeof(dp));
        int n;
        cin>>n;
        
        int A[n],B[n];
        
        long long ans = 0;
        long long sumA = 0,sumB = 0;
        for(int i = 0;i<n;++i){
            cin>>A[i];
            sumA+=A[i];
        }
        for(int i = 0;i<n;++i){
            cin>>B[i];
            ans+=(A[i]*A[i]) + (B[i]*B[i]);
            sumB+=B[i];
        }
        
        int mx = sumA + sumB;
        vector<int>dp(mx+1);
        long long z = (sumA*sumA)  + (sumB*sumB) ;
        long long val = 0;
        dp[0] = 1;
        for(int i = 0;i<n;++i){
            for(int j = mx;j>=0;--j){
                if(dp[j]){
                    if((j+A[i])<=mx){
                        dp[j+A[i]] = 1;
                    }
                    if((j+B[i])<=mx){
                        dp[j+B[i]] = 1;
                    }
                    dp[j] = 0;
                }
            }
        }
       //cout<<z<<" \n";
        
        for(int i = 0;i<=mx;++i){
           if(dp[i]){
              // cout<<(i)<<" ";
               val = (i*i) + ((mx-i)*(mx-i)) ;
               z = min(z,val);
           } 
        }
       // cout<<" \n";
        ans*=(n-2);
        
        ans+=z;
        
        cout<<ans<<"\n";
    }
}
