/*
Platform :- Leetcode
Approach :- It is a standard dp problem , and dp state is dp[i][j] = dp[i-1][j] + dp[i][j-1] , and if the cell is blocked dp[i][j] = 0 ,
            if(i==0 && j==0)dp[i][j]=1
            if(i==0)dp[i][j] = dp[i][j-1]
            if(j==0)dp[i][j] = dp[i-1][j]
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int ans=0;
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(i==0||j==0){
                   if(obstacleGrid[i][j]==1)dp[i][j]=0;
                   else{if(i==0&&j==0)dp[i][j]=1;
                    else if(j==0)dp[i][j]=dp[i-1][j];
                    else dp[i][j]=dp[i][j-1];
                    }
                }
                else{
                    if(obstacleGrid[i][j]==1)dp[i][j]=0;
                    else{
                        dp[i][j]=dp[i-1][j]+dp[i][j-1];
                    }
                }
            }
        }
        
        return dp[n-1][m-1];
    }
};
