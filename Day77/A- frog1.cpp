/*
Platform :- Atcoder
Approach :- Dp problem with 
           dp[0]=A[0]
           dp[1]=abs(A[1]-A[0]) , dp[2]=min(abs(A[2]-A[0],dp[1]+abs(A[2]-A[1])
           else dp[i]=min(dp[i-1]+abs(A[i]-A[i-1]) , dp[i-2]+abs(A[i]-A[i-2])
*/
