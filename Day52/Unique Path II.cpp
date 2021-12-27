/*
Platform :- Leetcode
Approach :- It is a standard dp problem , and dp state is dp[i][j] = dp[i-1][j] + dp[i][j-1] , and if the cell is blocked dp[i][j] = 0 ,
            if(i==0 && j==0)dp[i][j]=1
            if(i==0)dp[i][j] = dp[i][j-1]
            if(j==0)dp[i][j] = dp[i-1][j]
*/
